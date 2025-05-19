
#include "Enemy.h"
#include "Pipe.h"
#include "Animations.h"
#include "Mario.h"
#include "Bullet.h"
#include "PlayScene.h"
#include "Game.h"

CEnemy::CEnemy(float x, float y) : CGameObject(x, y)
{
	this->ax = 0;
	this->ay = 0;
	this->isUp = true;

	this->up_start = 0;
	this->down_start = 0;
	this->lastShootTime = 0;
	SetState(ENEMY_STATE_LEFT_DOWN);
}

void CEnemy::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - ENEMY_BBOX_WIDTH / 2;
	top = y - ENEMY_BBOX_HEIGHT / 2;
	right = left + ENEMY_BBOX_WIDTH;
	bottom = top + ENEMY_BBOX_HEIGHT;
}

void CEnemy::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CEnemy::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (dynamic_cast<CPipe*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
}

void CEnemy::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;
	ULONGLONG current_time = GetTickCount64();

	CMario* mario = nullptr;
	float marioX, marioY;
	bool isMarioLeft;
	bool isMarioAbove;
	for (auto obj : *coObjects)
	{
		mario = dynamic_cast<CMario*>(obj);
		if (mario) break;
	}
	if (mario)
	{

		mario->GetPosition(marioX, marioY);
		isMarioLeft = (marioX < x);
		isMarioAbove = (marioY < y);

		if (isMarioLeft && isMarioAbove)
			SetState(ENEMY_STATE_LEFT_UP);
		else if (isMarioLeft && !isMarioAbove)
			SetState(ENEMY_STATE_LEFT_DOWN);
		else if (!isMarioLeft && isMarioAbove)
			SetState(ENEMY_STATE_RIGHT_UP);
		else
			SetState(ENEMY_STATE_RIGHT_DOWN);
	}
	bool isMarioFar = (marioX < x - 35 || marioX > x + 35);

	if (isUp)
	{
		if (y > 310)
		{
			if (up_start == 0 && isMarioFar)
			{
				vy = -0.05f;
				up_start = current_time; 
			}
			else if (up_start != 0)
			{
				vy = -0.05f;
			}
			else
			{
				vy = 0;
			}
		}
		else 
		{
			vy = 0;
			y = 310;

			if (up_start != 0 && current_time - up_start >= ENEMY_UP_TIMEOUT)
			{
				isUp = false;
				up_start = 0;
			}
		}
	}
	else 
	{
		if (y < 350)
		{
			vy = 0.05f;
			down_start = 0;
		}
		else 
		{
			vy = 0;
			y = 350;

			if (down_start == 0)
				down_start = current_time;
			else if (current_time - down_start >= ENEMY_DOWN_TIMEOUT)
			{
				if (isMarioFar)
				{
					isUp = true; 
					up_start = 0; 
				}
				down_start = 0;
			}
		}
	}

	if (isUp && fabs(y - 310.0f) < 0.1f)  
	{
		CMario* mario = nullptr;
		for (auto obj : *coObjects)
		{
			mario = dynamic_cast<CMario*>(obj);
			if (mario) break;
		}

		if (mario)
		{
			float marioX, marioY;
			mario->GetPosition(marioX, marioY);
			float distX = fabs(marioX - x);

			if (distX <= ENEMY_SHOOT_RANGE && (current_time - lastShootTime) >= ENEMY_SHOOT_COOLDOWN && mario->GetState() != MARIO_STATE_DIE)
			{
				if (isMarioLeft && isMarioAbove)
				{
					if (marioX > 305) {
						ShootBullet(320, 260);
						lastShootTime = current_time;
					}
					else {
						ShootBullet(320, 288);
						lastShootTime = current_time;
					}
				}
				else if (isMarioLeft && !isMarioAbove)
				{
					if (marioX > 305) {
						ShootBullet(330, 366);
						lastShootTime = current_time;
					}
					else {
						ShootBullet(220, 366);
						lastShootTime = current_time;
					}
				}
				else if (!isMarioLeft && isMarioAbove)
				{

					if (marioX > 475) {
						ShootBullet(450, 295);
						lastShootTime = current_time;
					}
					else {
						ShootBullet(450, 255);
						lastShootTime = current_time;
					}
				}
				else
				{
					if (marioX > 475) {
						ShootBullet(563, 366);
						lastShootTime = current_time;
					}
					else {
						ShootBullet(450, 366);
						lastShootTime = current_time;
					}
				}
			}
		}
	}

	vector<LPGAMEOBJECT> filtered;
	for (auto obj : *coObjects)
	{
		if (!dynamic_cast<CPipe*>(obj))
			filtered.push_back(obj);
	}

	CGameObject::Update(dt, &filtered);
	CCollision::GetInstance()->Process(this, dt, &filtered);
}
void CEnemy::ShootBullet(float targetX, float targetY)
{
	float dx = targetX - x;
	float dy = targetY - y;


	float length = sqrt(dx * dx + dy * dy);
	if (length == 0) return; 

	float speed = 0.05f; 
	float bulletVx = dx / length * speed;
	float bulletVy = dy / length * speed;

	CBullet* bullet = new CBullet(x, y - 10, bulletVx, bulletVy);
	CGame::GetInstance()->GetCurrentScene()->AddObject(bullet);
}

void CEnemy::Render()
{
	int aniId = ID_ANI_ENEMY_LEFT_DOWN;

	switch (state)
	{
	case ENEMY_STATE_LEFT_DOWN:
		aniId = ID_ANI_ENEMY_LEFT_DOWN;
		break;
	case ENEMY_STATE_LEFT_UP:
		aniId = ID_ANI_ENEMY_LEFT_UP;
		break;
	case ENEMY_STATE_RIGHT_DOWN:
		aniId = ID_ANI_ENEMY_RIGHT_DOWN;
		break;
	case ENEMY_STATE_RIGHT_UP:
		aniId = ID_ANI_ENEMY_RIGHT_UP;
		break;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}

void CEnemy::SetState(int state)
{
	CGameObject::SetState(state);
	// Nếu bạn cần logic chuyển trạng thái, có thể thêm ở đây
}
