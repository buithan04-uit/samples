#include "Cloud.h"

void CCloud::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	if (this->type == 0)
		animations->Get(ID_ANI_CLOUD_SMALL)->Render(x, y);
	else if (this->type == 1)
		animations->Get(ID_ANI_CLOUD_MEDIUM)->Render(x, y);
	else if (this->type == 2)
		animations->Get(ID_ANI_CLOUD_LARGE)->Render(x, y);
	//RenderBoundingBox();
}

void CCloud::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (this->type == 0)
	{
		l = x - CLOUD_SMALL_BBOX_WIDTH / 2;
		t = y - CLOUD_SMALL_BBOX_HEIGHT / 2;
		r = l + CLOUD_SMALL_BBOX_WIDTH;
		b = t + CLOUD_SMALL_BBOX_HEIGHT;
	}
	else if (this->type == 1)
	{
		l = x - CLOUD_MEDIUM_BBOX_WIDTH / 2;
		t = y - CLOUD_MEDIUM_BBOX_HEIGHT / 2;
		r = l + CLOUD_MEDIUM_BBOX_WIDTH;
		b = t + CLOUD_MEDIUM_BBOX_HEIGHT;
	}
	else if (this->type == 2)
	{
		l = x - CLOUD_LARGE_BBOX_WIDTH / 2;
		t = y - CLOUD_LARGE_BBOX_HEIGHT / 2;
		r = l + CLOUD_LARGE_BBOX_WIDTH;
		b = t + CLOUD_LARGE_BBOX_HEIGHT;
	}

}
