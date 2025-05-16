#include "Fallsensor.h"
#include "Koopas.h"
#include "Mario.h"

CFallsensor::CFallsensor(float x, float y) : CGameObject(x, y) {
    this->ax = 0;
    this->ay = KOOPAS_GRAVITY;
}

void CFallsensor::GetBoundingBox(float& left, float& top, float& right, float& bottom) {
	if (state == KOOPAS_STATE_SHELL || state == KOOPAS_STATE_KICK)
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

int CFallsensor::IsDirectionColliable(float nx, float ny)
{
	if (nx == 0 && ny == 1) return 1;
	else return 0;
}

void CFallsensor::OnNoCollision(DWORD dt) {
    x += vx * dt;
    y += vy * dt;
}

void CFallsensor::OnCollisionWith(LPCOLLISIONEVENT e ) {
    if (!e->obj->IsBlocking()) return;

    if (e->ny != 0) {
        vy = 0;
    }
	
}

void CFallsensor::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {

	vy += ay * dt;
	vx += ax * dt;

    CGameObject::Update(dt, coObjects);
    CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CFallsensor::Render() {
    RenderBoundingBox(); 
}
