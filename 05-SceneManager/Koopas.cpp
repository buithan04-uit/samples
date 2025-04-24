#include "Koopas.h"
#include "Goomba.h"

CKoopas::CKoopas(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = KOOPAS_GRAVITY;
	die_start = -1;
	shell_start = -1;
	SetState(KOOPAS_STATE_WALKING);
	fallsensor = new CFallsensor(x + KOOPAS_BBOX_WIDTH + 1, y);
}

void CKoopas::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state == KOOPAS_STATE_DIE)
	{
		left = x - KOOPAS_BBOX_WIDTH / 2;
		top = y - KOOPAS_BBOX_HEIGHT_DIE / 2;
		right = left + KOOPAS_BBOX_WIDTH;
		bottom = top + KOOPAS_BBOX_HEIGHT_DIE;
	}
	else if (state == KOOPAS_STATE_SHELL || state == KOOPAS_STATE_KICK)
	{
		left = x - KOOPAS_BBOX_WIDTH / 2;
		top = y - KOOPAS_BBOX_HEIGHT_SHELL / 2;
		right = left + KOOPAS_BBOX_WIDTH;
		bottom = top + KOOPAS_BBOX_HEIGHT_SHELL;
	}
	else
	{
		left = x - KOOPAS_BBOX_WIDTH / 2;
		top = y - KOOPAS_BBOX_HEIGHT / 2;
		right = left + KOOPAS_BBOX_WIDTH;
		bottom = top + KOOPAS_BBOX_HEIGHT;
	}
}

void CKoopas::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CKoopas::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (dynamic_cast<CGoomba*>(e->obj)) OnCollisionWithGoomba(e);
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CKoopas*>(e->obj)) return;


	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
		if (state == KOOPAS_STATE_WALKING) {
			if (vx > 0) {
				fallsensor->SetPosition(x + KOOPAS_BBOX_WIDTH + 1, y);
			}
			else {
				fallsensor->SetPosition(x - KOOPAS_BBOX_WIDTH - 1, y);
			}
		}
	}
}
void CKoopas::OnCollisionWithGoomba(LPCOLLISIONEVENT e) {
	CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);
	if (state == KOOPAS_STATE_KICK)
	{
		goomba->SetState(GOOMBA_STATE_DIE);
	}
}

void CKoopas::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	if ((state == KOOPAS_STATE_DIE) && (GetTickCount64() - die_start > KOOPAS_DIE_TIMEOUT))
	{
		isDeleted = true;
		return;
	}
	if ((state == KOOPAS_STATE_SHELL || state == KOOPAS_STATE_KICK) && (GetTickCount64() - shell_start > KOOPAS_SHELL_TIMEOUT))
	{
		state = KOOPAS_STATE_WALKING;
		y -= (KOOPAS_BBOX_HEIGHT - KOOPAS_BBOX_HEIGHT_SHELL) / 2;
		vx = -KOOPAS_WALKING_SPEED;
		if (state != KOOPAS_STATE_SHELL && state != KOOPAS_STATE_KICK) {
			if (vx > 0) {
				fallsensor->SetPosition(x + KOOPAS_BBOX_WIDTH + 1, y);
			}
			else {
				fallsensor->SetPosition(x - KOOPAS_BBOX_WIDTH - 1, y);
			}
		}
	}
	if (state == KOOPAS_STATE_WALKING) {
		if (fallsensor->GetVy() != 0) {
			vx = -vx;
			if (vx > 0) {
				fallsensor->SetPosition(x + KOOPAS_BBOX_WIDTH + 1, y);
			}
			else {
				fallsensor->SetPosition(x - KOOPAS_BBOX_WIDTH - 1, y);
			}
		}
	}
	if (state == KOOPAS_STATE_WALKING) {
		fallsensor->setSpeed(vx);
	}
	else {
		fallsensor->setSpeed(0);
	}

	fallsensor->Update(dt, coObjects);
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CKoopas::Render()
{
	int aniId;
	if (vx < 0) {
		aniId = ID_ANI_KOOPAS_WALKING_LEFT;
	}
	else {
		aniId = ID_ANI_KOOPAS_WALKING_RIGHT;
	}
	if (state == KOOPAS_STATE_SHELL)
	{
		aniId = ID_ANI_KOOPAS_SHELL;
	}
	if (state == KOOPAS_STATE_KICK)
	{
		aniId = ID_ANI_KOOPAS_KICK;
	}

	fallsensor->Render();
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CKoopas::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case KOOPAS_STATE_SHELL:
		shell_start = GetTickCount64();
		y += (KOOPAS_BBOX_HEIGHT - KOOPAS_BBOX_HEIGHT_SHELL) / 2;
		vx = 0;
		vy = 0;
		ay = 0;
		break;
	case KOOPAS_STATE_WALKING:
		vx = -KOOPAS_WALKING_SPEED;
		break;
	case KOOPAS_STATE_KICK:
		vy = 0;
		ay = 0;
		break;
	}
}