#include "GiftBox.h"
#include "debug.h"

void CGiftBox::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{


}
void CGiftBox::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	if (state == GIFTBOX_STATE_IDLE) animations->Get(ID_ANI_GIFTBOX)->Render(x, y);
	if (state == GIFTBOX_STATE_PICKED) animations->Get(ID_ANI_GIFTBOX_PICKED)->Render(x, y);
	//RenderBoundingBox();

}

void CGiftBox::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - GIFTBOX_BBOX_WIDTH / 2;
	t = y - GIFTBOX_BBOX_HEIGHT / 2;
	r = l + GIFTBOX_BBOX_WIDTH;
	b = t + GIFTBOX_BBOX_HEIGHT;
}
void CGiftBox::SetState(int state)
{
	this->state = state;
}