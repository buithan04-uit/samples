#include "Brick.h"

void CBrick::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	if (this->state == BRICK_STATE_IDLE) animations->Get(ID_ANI_BRICK)->Render(x, y);
	else if (this->state == BRICK_STATE_1)
		animations->Get(ID_ANI_BRICK_1)->Render(x, y);
	else if (this->state == BRICK_STATE_2)
		animations->Get(ID_ANI_BRICK_2)->Render(x, y);
	//RenderBoundingBox();
}

void CBrick::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x - BRICK_BBOX_WIDTH/2;
	t = y - BRICK_BBOX_HEIGHT/2;
	r = l + BRICK_BBOX_WIDTH;
	b = t + BRICK_BBOX_HEIGHT;
}