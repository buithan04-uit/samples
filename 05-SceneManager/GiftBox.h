#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_GIFTBOX 50000
#define ID_ANI_GIFTBOX_PICKED 50001
#define GIFTBOX_WIDTH 15
#define GIFTBOX_BBOX_WIDTH 15
#define GIFTBOX_BBOX_HEIGHT 15

#define GIFTBOX_STATE_IDLE 0
#define GIFTBOX_STATE_PICKED 1

class CGiftBox : public CGameObject {
public:
	CGiftBox(float x, float y, int state) : CGameObject(x, y) { this->state = state; }
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void SetState(int state);
	float GetX() { return x; }
	float GetY() { return y; }
};