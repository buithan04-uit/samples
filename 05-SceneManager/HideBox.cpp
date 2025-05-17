#include "HideBox.h"

void CHideBox::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	RenderBoundingBox();
}

void CHideBox::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - HIDE_BBOX_WIDTH / 2;
	t = y - HIDE_BBOX_HEIGHT / 2;
	r = l + HIDE_BBOX_WIDTH;
	b = t + HIDE_BBOX_HEIGHT;
}