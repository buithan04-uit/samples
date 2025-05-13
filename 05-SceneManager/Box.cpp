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
		boxCollision = new CBoxCollision(x - 138 , y + 32 , 79, 47);
		CGame::GetInstance()->GetCurrentScene()->AddObject(boxCollision);
		boxCollision = new CBoxCollision(x - 82, y + 16, 62, 79);
		CGame::GetInstance()->GetCurrentScene()->AddObject(boxCollision);
		boxCollision = new CBoxCollision(x  - 18 , y + 40 , 95, 31);
		CGame::GetInstance()->GetCurrentScene()->AddObject(boxCollision);
		boxCollision = new CBoxCollision(x - 33, y , 63, 111);
		CGame::GetInstance()->GetCurrentScene()->AddObject(boxCollision);
	}
	else if (type == 2) {
		boxCollision = new CBoxCollision(x - 73 , y - 4, 79, 31);
		CGame::GetInstance()->GetCurrentScene()->AddObject(boxCollision);
	}
	else if (type == 3) {
		boxCollision = new CBoxCollision(x - 106, y + 32 , 111 , 31);
		CGame::GetInstance()->GetCurrentScene()->AddObject(boxCollision);
		boxCollision = new CBoxCollision(x - 74, y + 16, 111, 63);
		CGame::GetInstance()->GetCurrentScene()->AddObject(boxCollision);
		boxCollision = new CBoxCollision(x - 42, y, 111, 95);
		CGame::GetInstance()->GetCurrentScene()->AddObject(boxCollision);
	}
	else if (type == 4) {
		boxCollision = new CBoxCollision(x - 90 , y + 48, 47, 47);
		CGame::GetInstance()->GetCurrentScene()->AddObject(boxCollision);
		boxCollision = new CBoxCollision(x - 58, y , 47, 143);
		CGame::GetInstance()->GetCurrentScene()->AddObject(boxCollision);
	}
	else {
		DebugOut(L"[ERROR] Invalid Box type: %d\n", type);
	}
}

void CBox::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	if (this->type == BOX_TYPE_1)
		animations->Get(ID_ANI_BOX_1)->Render(x, y);
	else if (this->type == BOX_TYPE_2)
		animations->Get(ID_ANI_BOX_2)->Render(x, y);
	else if (this->type == BOX_TYPE_3)
		animations->Get(ID_ANI_BOX_3)->Render(x, y);
	else if (this->type == BOX_TYPE_4)
		animations->Get(ID_ANI_BOX_4)->Render(x, y);
	else if (this->type == BOX_TYPE_5)
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
