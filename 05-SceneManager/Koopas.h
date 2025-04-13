#pragma once
#include "GameObject.h"

#define KOOPAS_GRAVITY 0.002f
#define KOOPAS_WALKING_SPEED 0.05f


#define KOOPAS_BBOX_WIDTH 17
#define KOOPAS_BBOX_HEIGHT 26
#define KOOPAS_BBOX_HEIGHT_SHELL 16
#define KOOPAS_BBOX_HEIGHT_DIE 7

#define KOOPAS_SHELL_TIMEOUT 10000
#define KOOPAS_DIE_TIMEOUT 500

#define KOOPAS_STATE_WALKING 100
#define KOOPAS_STATE_SHELL 200
#define KOOPAS_STATE_DIE 300
#define KOOPAS_STATE_KICK 400


#define ID_ANI_KOOPAS_WALKING_RIGHT 6000
#define ID_ANI_KOOPAS_WALKING_LEFT 6001
#define ID_ANI_KOOPAS_SHELL 6002
#define ID_ANI_KOOPAS_KICK 6003
#define ID_ANI_KOOPAS_DIE 6004

class CKoopas : public CGameObject
{
protected:
	float ax;
	float ay;

	ULONGLONG die_start;
	ULONGLONG shell_start;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);


public:
	CKoopas(float x, float y);
	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	virtual void SetState(int state);
};