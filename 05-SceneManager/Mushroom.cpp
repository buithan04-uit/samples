
#include "Mushroom.h"
#include "Animations.h"
#include "Game.h"
#include "GiftBox.h"
#include "Mario.h"

CMushroom::CMushroom(float x, float y) : CGameObject(x, y)
{
	this->ax = 0;
	this->ay = 0;
	this->vx = 0;
	this->vy = -0.03f; 
	this->isEmerging = true;
	this->emergeTargetY = y - MUSHROOM_BBOX_HEIGHT; 
	this->die_start = GetTickCount64();
}

void CMushroom::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - MUSHROOM_BBOX_WIDTH / 2;
	top = y - MUSHROOM_BBOX_HEIGHT / 2;
	right = left + MUSHROOM_BBOX_WIDTH;
	bottom = top + MUSHROOM_BBOX_HEIGHT;
}

void CMushroom::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CMushroom::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;

	if (isEmerging && dynamic_cast<CGiftBox*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CMushroom::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	
	if (isEmerging)
	{
		y += vy * dt;

		if (y <= emergeTargetY)
		{
			y = emergeTargetY;
			vy = 0;
			isEmerging = false;

			ay = MUSHROOM_GRAVITY;

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

				bool isMarioLeft = (marioX < x);

				if (isMarioLeft)
				{
					vx = 0.15f; ;
				}
				else
				{
					vx = -0.15f;
				}
			}
			 
		}
	}
	else
	{
		vy += ay * dt;
		vx += ax * dt;

		CGameObject::Update(dt, coObjects);
		CCollision::GetInstance()->Process(this, dt, coObjects);
	}

	// Tự hủy sau timeout
	if (GetTickCount64() - die_start > MUSHROOM_TIMEOUT)
	{
		isDeleted = true;
	}
}



void CMushroom::Render()
{
	int aniId = ID_ANI_MUSHROOM;

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}

void CMushroom::SetState(int state)
{
	CGameObject::SetState(state);
	if (state == MUSHROOM_STATE_DIE)
	{
		isDeleted = true;
	}
}
