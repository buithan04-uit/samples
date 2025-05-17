#include "Bullet.h"


CBullet::CBullet(float x, float y, float vx , float vy) : CGameObject(x, y)
{
    this->vx = vx;
    this->vy = vy;
	this->ax = 0;
	this->ay = 0;
    bornTime = GetTickCount64();
}
void CBullet::OnNoCollision(DWORD dt) {
    x += vx * dt;
    y += vy * dt;
}

void CBullet::OnCollisionWith(LPCOLLISIONEVENT e) {
	isDeleted = true;
}
void CBullet::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
    vx += ax * dt;
	vy += ay * dt;

	if (GetTickCount64() - bornTime > BULLET_TIMEOUT) {
		isDeleted = true;
	}
    CGameObject::Update(dt, coObjects);
    CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CBullet::Render()
{
    CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_BULLET)->Render(x, y);
	//RenderBoundingBox();
}

void CBullet::GetBoundingBox(float& l, float& t, float& r, float& b)
{
    l = x - BULLET_BBOX_WIDTH / 2;
    t = y - BULLET_BBOX_HEIGHT / 2;
    r = l + BULLET_BBOX_WIDTH;
    b = t + BULLET_BBOX_HEIGHT;
}
