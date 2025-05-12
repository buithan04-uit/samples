#include "Pipe.h"

void CPipe::Render()
{
	CAnimations* animations = CAnimations::GetInstance();

	if (this->state == 0)
		animations->Get(ID_ANI_PIPE_1)->Render(x, y);
	else if (this->state == 1)
		animations->Get(ID_ANI_PIPE_2)->Render(x, y);
	else if (this->state == 2)
		animations->Get(ID_ANI_PIPE_3)->Render(x, y);
	else if (this->state == 3)
		animations->Get(ID_ANI_PIPE_4)->Render(x, y);
	//RenderBoundingBox();
}

void CPipe::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (this->state == 0) {
		l = x - PIPE_1_BBOX_WIDTH / 2;
		t = y - PIPE_1_BBOX_HEIGHT / 2;
		r = l + PIPE_1_BBOX_WIDTH;
		b = t + PIPE_1_BBOX_HEIGHT;
	}
	else if (this->state == 1) {
		l = x - PIPE_2_BBOX_WIDTH / 2;
		t = y - PIPE_2_BBOX_HEIGHT / 2;
		r = l + PIPE_2_BBOX_WIDTH;
		b = t + PIPE_2_BBOX_HEIGHT;
	}
	else if (this->state == 2) {
		l = x - PIPE_3_BBOX_WIDTH / 2;
		t = y - PIPE_3_BBOX_HEIGHT / 2;
		r = l + PIPE_3_BBOX_WIDTH;
		b = t + PIPE_3_BBOX_HEIGHT;
	}
	else if (this->state == 3) {
		l = x - PIPE_4_BBOX_WIDTH / 2;
		t = y - PIPE_4_BBOX_HEIGHT / 2;
		r = l + PIPE_4_BBOX_WIDTH;
		b = t + PIPE_4_BBOX_HEIGHT;
	}
}
