#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define BRICK_STATE_IDLE 0
#define BRICK_STATE_1 1
#define BRICK_STATE_2 2

#define ID_ANI_BRICK 10000
#define ID_ANI_BRICK_1 10001
#define ID_ANI_BRICK_2 10002

#define BRICK_WIDTH 15
#define BRICK_BBOX_WIDTH 15
#define BRICK_BBOX_HEIGHT 15

class CBrick : public CGameObject {
public:
	CBrick(float x, float y, int state) : CGameObject(x, y) { this->state = state; }
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};