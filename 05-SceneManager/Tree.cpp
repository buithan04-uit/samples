#include "Tree.h"

void CTree::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	if (this->state == STATE_TREE_SMALL) animations->Get(ID_ANI_TREE_SMALL)->Render(x, y);
	else if (this->state == STATE_TREE_MEDIUM)
		animations->Get(ID_ANI_TREE_MEDIUM)->Render(x, y);
	else if (this->state == STATE_TREE_LARGE)
		animations->Get(ID_ANI_TREE_LARGE)->Render(x, y);
	else if (this->state == STATE_TREE_SUPER)
		animations->Get(ID_ANI_TREE_SUPER)->Render(x, y);
	else if (this->state == STATE_TREE_ULTRA)
		animations->Get(ID_ANI_TREE_ULTRA)->Render(x, y);
	//RenderBoundingBox();
}

void CTree::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - TREE_SMALL_BBOX_WIDTH / 2;
	t = y - TREE_SMALL_BBOX_HEIGHT / 2;
	r = l + TREE_SMALL_BBOX_WIDTH;
	b = t + TREE_SMALL_BBOX_HEIGHT;
}
