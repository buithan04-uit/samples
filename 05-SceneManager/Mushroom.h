#pragma once
#include "GameObject.h"


#define MUSHROOM_BBOX_WIDTH 15
#define MUSHROOM_BBOX_HEIGHT 15

#define MUSHROOM_GRAVITY 0.002f

#define ID_ANI_MUSHROOM 110011

#define MUSHROOM_TIMEOUT 5000
#define MUSHROOM_STATE_IDLE 0
#define MUSHROOM_STATE_DIE 1


class CMushroom : public CGameObject
{
protected:
	float ax;
	float ay;

	ULONGLONG die_start;
	bool isEmerging;   
	float emergeTargetY; 
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CMushroom(float x, float y);
	virtual void SetState(int state);
};