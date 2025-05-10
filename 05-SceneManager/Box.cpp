#include "Box.h"
#include "vector"
#include "Game.h"
CBox::CBox(float x, float y, int type) : CGameObject(x, y)
{
	this->type = type;

	CBoxCollision* boxCollision = nullptr;
	if (type == 0) {
		boxCollision = new CBoxCollision(x - BOX_1_BBOX_WIDTH - 2  , y + 15 , 47, 47);
		CGame::GetInstance()->GetCurrentScene()->AddObject(boxCollision);
		boxCollision = new CBoxCollision(x - BOX_1_BBOX_WIDTH / 2 - 15, y , 47, 79);
		CGame::GetInstance()->GetCurrentScene()->AddObject(boxCollision);
	}
	else if (type == 1) {
		boxCollision = new CBoxCollision(x - 60, y + 30, BOX_2_BBOX_WIDTH, BOX_2_BBOX_HEIGHT);
		CGame::GetInstance()->GetCurrentScene()->AddObject(boxCollision);
	}
	else if (type == 2) {
		boxCollision = new CBoxCollision(x - 5 * BOX_1_BBOX_WIDTH / 6 + 3, y, BOX_3_BBOX_WIDTH, BOX_3_BBOX_HEIGHT);
		CGame::GetInstance()->GetCurrentScene()->AddObject(boxCollision);
	}
	else if (type == 3) {
		boxCollision = new CBoxCollision(x - 5 * BOX_1_BBOX_WIDTH / 6 + 3, y, BOX_4_BBOX_WIDTH, BOX_4_BBOX_HEIGHT);
		CGame::GetInstance()->GetCurrentScene()->AddObject(boxCollision);
	}
	else if (type == 4) {
		boxCollision = new CBoxCollision(x - 5 * BOX_1_BBOX_WIDTH / 6 + 3, y, BOX_5_BBOX_WIDTH, BOX_5_BBOX_HEIGHT);
		CGame::GetInstance()->GetCurrentScene()->AddObject(boxCollision);
	}
	else {
		DebugOut(L"[ERROR] Invalid Box type: %d\n", type);
	}
}

void CBox::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	if (this->type == 0)
		animations->Get(ID_ANI_BOX_1)->Render(x, y);
	else if (this->type == 1)
		animations->Get(ID_ANI_BOX_2)->Render(x, y);
	else if (this->type == 2)
		animations->Get(ID_ANI_BOX_3)->Render(x, y);
	else if (this->type == 3)
		animations->Get(ID_ANI_BOX_4)->Render(x, y);
	else if (this->type == 4)
		animations->Get(ID_ANI_BOX_5)->Render(x, y);
	//RenderBoundingBox();
}

void CBox::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (this->type == 0)
	{
		l = x - BOX_1_WIDTH / 2;
		t = y - BOX_1_BBOX_HEIGHT / 2;
		r = l + BOX_1_BBOX_WIDTH;
		b = t + BOX_1_BBOX_HEIGHT;
	}
	else if (this->type == 1)
	{
		l = x - BOX_2_WIDTH / 2;
		t = y - BOX_2_BBOX_HEIGHT / 2;
		r = l + BOX_2_BBOX_WIDTH;
		b = t + BOX_2_BBOX_HEIGHT;
	}
	else if (this->type == 2)
	{
		l = x - BOX_3_WIDTH / 2;
		t = y - BOX_3_BBOX_HEIGHT / 2;
		r = l + BOX_3_BBOX_WIDTH;
		b = t + BOX_3_BBOX_HEIGHT;
	}
	else if (this->type == 3)
	{
		l = x - BOX_4_WIDTH / 2;
		t = y - BOX_4_BBOX_HEIGHT / 2;
		r = l + BOX_4_BBOX_WIDTH;
		b = t + BOX_4_BBOX_HEIGHT;
	}
	else if (this->type == 4)
	{
		l = x - BOX_5_WIDTH / 2;
		t = y - BOX_5_BBOX_HEIGHT / 2;
		r = l + BOX_5_BBOX_WIDTH;
		b = t + BOX_5_BBOX_HEIGHT;
	}
}
