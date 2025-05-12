#include "Star.h"

void CStar::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	if (this->type == 0)
		animations->Get(ID_ANI_STAR_1)->Render(x, y);
	else if (this->type == 1)
		animations->Get(ID_ANI_STAR_2)->Render(x, y);
	else if (this->type == 2)
		animations->Get(ID_ANI_STAR_3)->Render(x, y);

	//RenderBoundingBox();
}

void CStar::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (this->type == 0)
	{
		l = x - STAR_1_BBOX_WIDTH / 2;
		t = y - STAR_1_BBOX_HEIGHT / 2;
		r = l + STAR_1_BBOX_WIDTH;
		b = t + STAR_1_BBOX_HEIGHT;
	}
	else if (this->type == 1)
	{
		l = x - STAR_2_BBOX_WIDTH / 2;
		t = y - STAR_2_BBOX_HEIGHT / 2;
		r = l + STAR_2_BBOX_WIDTH;
		b = t + STAR_2_BBOX_HEIGHT;
	}
	else if (this->type == 2)
	{
		l = x - STAR_3_BBOX_WIDTH / 2;
		t = y - STAR_3_BBOX_HEIGHT / 2;
		r = l + STAR_3_BBOX_WIDTH;
		b = t + STAR_3_BBOX_HEIGHT;
	}
}
