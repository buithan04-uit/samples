#include "Goomba.h"
#include "Animations.h"
#include "HideBox.h"

CGoomba::CGoomba(float x, float y , int type) : CGameObject(x, y)  
{  
   this->ax = 0;    
   die_start = -1;  
   this->type = type;
   if (type == 0)
   {
	   SetState(GOOMBA_STATE_WALKING);
	   this->ay = GOOMBA_GRAVITY;
   }
   else if (type == 1)
   {
	   SetState(GOOMBA_1_STATE_WALKING);
	   this->ay = GOOMBA_GRAVITY;
   }
   else if (type == 2)
   {
	   SetState(GOOMBA_1_STATE_FLY);
	   this->ay = GOOMBA_1_GRAVITY;
   }
}

void CGoomba::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	if (state == GOOMBA_STATE_DIE)
	{
		left = x - GOOMBA_BBOX_WIDTH/2;
		top = y - GOOMBA_BBOX_HEIGHT_DIE/2;
		right = left + GOOMBA_BBOX_WIDTH;
		bottom = top + GOOMBA_BBOX_HEIGHT_DIE;
	}
	else if (state == GOOMBA_STATE_WALKING)
	{
		left = x - GOOMBA_BBOX_WIDTH / 2;
		top = y - GOOMBA_BBOX_HEIGHT / 2;
		right = left + GOOMBA_BBOX_WIDTH;
		bottom = top + GOOMBA_BBOX_HEIGHT;
	}
	else if (state == GOOMBA_1_STATE_FLY)
	{
		left = x - GOOMBA_1_FLY_BBOX_WIDTH / 2;
		top = y - GOOMBA_1_FLY_BBOX_HEIGHT / 2;
		right = left + GOOMBA_1_FLY_BBOX_WIDTH;
		bottom = top + GOOMBA_1_FLY_BBOX_HEIGHT;
	}
	else if (state == GOOMBA_1_STATE_WALKING)
	{
		left = x - GOOMBA_1_BBOX_WIDTH / 2;
		top = y - GOOMBA_1_BBOX_HEIGHT / 2;
		right = left + GOOMBA_1_BBOX_WIDTH;
		bottom = top + GOOMBA_1_BBOX_HEIGHT;
	}
	else if (state == GOOMBA_1_STATE_DIE)
	{ 
		left = x - GOOMBA_1_BBOX_WIDTH/2;
		top = y - GOOMBA_1_BBOX_HEIGHT/2;
		right = left + GOOMBA_1_BBOX_WIDTH;
		bottom = top + GOOMBA_1_BBOX_HEIGHT_DIE;
	}
}

void CGoomba::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CGoomba::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (dynamic_cast<CHideBox*>(e->obj))
	{
		vx = -vx;
		return; 
	}

	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CGoomba*>(e->obj)) return;

	if (e->ny != 0)
	{
		if (state == GOOMBA_1_STATE_FLY)
			vy = -GOOMBA_1_JUMP_SPEED_Y;
		else
			vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CGoomba::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	if ( (state==GOOMBA_STATE_DIE || state == GOOMBA_1_STATE_DIE) && (GetTickCount64() - die_start > GOOMBA_DIE_TIMEOUT) )
	{
		isDeleted = true;
		return;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CGoomba::Render()
{
	int aniId = ID_ANI_GOOMBA_WALKING;
	if (state == GOOMBA_STATE_DIE) 
	{
		aniId = ID_ANI_GOOMBA_DIE;
	}
	else if (state == GOOMBA_1_STATE_FLY)
	{
		aniId = ID_ANI_GOOMBA_1_FLY;
	}
	else if (state == GOOMBA_1_STATE_WALKING)
	{
		aniId = ID_ANI_GOOMBA_1_WALKING;
	}
	else if (state == GOOMBA_1_STATE_DIE)
	{
		aniId = ID_ANI_GOOMBA_1_DIE;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x,y);
	RenderBoundingBox();
}

void CGoomba::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
		case GOOMBA_STATE_DIE:
			die_start = GetTickCount64();
			y += (GOOMBA_BBOX_HEIGHT - GOOMBA_BBOX_HEIGHT_DIE)/2;
			vx = 0;
			vy = 0;
			ay = 0; 
			break;
		case GOOMBA_STATE_WALKING: 
			vx = -GOOMBA_WALKING_SPEED;
			break;
		case GOOMBA_1_STATE_FLY:
			vx = -2 * GOOMBA_WALKING_SPEED;
			break;
		case GOOMBA_1_STATE_WALKING:
			y += (GOOMBA_1_FLY_BBOX_HEIGHT - GOOMBA_1_BBOX_HEIGHT) / 2;
			vx = -GOOMBA_WALKING_SPEED;
			break;
		case GOOMBA_1_STATE_DIE:
			die_start = GetTickCount64();
			y += (GOOMBA_1_BBOX_HEIGHT - GOOMBA_1_BBOX_HEIGHT_DIE) / 2;
			vx = 0;
			vy = 0;
			ay = 0;
			break;
	}
}
