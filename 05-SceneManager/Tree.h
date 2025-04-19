#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define STATE_TREE_SMALL 0
#define STATE_TREE_MEDIUM 1
#define STATE_TREE_LARGE 2
#define STATE_TREE_SUPER 3
#define STATE_TREE_ULTRA 4

#define ID_ANI_TREE_SMALL 40000
#define ID_ANI_TREE_MEDIUM 40001
#define ID_ANI_TREE_LARGE 40002
#define ID_ANI_TREE_SUPER 40003
#define ID_ANI_TREE_ULTRA 40004

#define TREE_SMALL_WIDTH 15
#define TREE_SMALL_BBOX_WIDTH 15
#define TREE_SMALL_BBOX_HEIGHT 17

#define TREE_MEDIUM_WIDTH 15
#define TREE_MEDIUM_BBOX_WIDTH 15
#define TREE_MEDIUM_BBOX_HEIGHT 17

#define TREE_LARGE_WIDTH 15
#define TREE_LARGE_BBOX_WIDTH 15
#define TREE_LARGE_BBOX_HEIGHT 17

class CTree : public CGameObject {
public:
	CTree(float x, float y, int state) : CGameObject(x, y) { this->state = state; }
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() override { return 0; }
};