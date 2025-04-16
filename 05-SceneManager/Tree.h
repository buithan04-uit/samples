#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_TREE 40000
#define TREE_WIDTH 15
#define TREE_BBOX_WIDTH 15
#define TREE_BBOX_HEIGHT 17

class CTree : public CGameObject {
public:
	CTree(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() override { return 0; }
};