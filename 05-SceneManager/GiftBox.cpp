#include "GiftBox.h"

void CGiftBox::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
void CGiftBox::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	if (this->state == GIFTBOX_STATE_IDLE) animations->Get(ID_ANI_GIFTBOX)->Render(x, y);
	if (this->state == GIFTBOX_STATE_PICKED) animations->Get(ID_ANI_GIFTBOX_PICKED)->Render(x, y);
	//RenderBoundingBox();
}

void CGiftBox::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - GIFTBOX_BBOX_WIDTH / 2;
	t = y - GIFTBOX_BBOX_HEIGHT / 2;
	r = l + GIFTBOX_BBOX_WIDTH;
	b = t + GIFTBOX_BBOX_HEIGHT;
}