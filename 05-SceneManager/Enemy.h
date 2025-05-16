#pragma once
#include "GameObject.h"

// Các hằng số cho chức năng bắn đạn
#define ENEMY_SHOOT_RANGE 200.0f       // Phạm vi mà enemy nhận biết Mario
#define ENEMY_SHOOT_COOLDOWN 2000      // 2000 ms giữa các lần bắn 


#define ENEMY_BBOX_WIDTH 15
#define ENEMY_BBOX_HEIGHT 31
#define ENEMY_BBOX_HEIGHT_DIE 7

#define ENEMY_UP_TIMEOUT 3000
#define ENEMY_DOWN_TIMEOUT 3000


#define ENEMY_STATE_LEFT_DOWN 100
#define ENEMY_STATE_LEFT_UP 200
#define ENEMY_STATE_RIGHT_DOWN 300
#define ENEMY_STATE_RIGHT_UP 400

#define ID_ANI_ENEMY_LEFT_DOWN 90011
#define ID_ANI_ENEMY_LEFT_UP 90012
#define ID_ANI_ENEMY_RIGHT_DOWN 90013
#define ID_ANI_ENEMY_RIGHT_UP 90014

class CEnemy : public CGameObject
{
protected:
	float ax;
	float ay;
	bool isUp;

	ULONGLONG up_start;
	ULONGLONG down_start;
	ULONGLONG lastShootTime;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e );
	void ShootBullet(float targetX, float targetY);

public:
	CEnemy(float x, float y);
	virtual void SetState(int state);
};