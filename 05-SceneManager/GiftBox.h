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

#define GIFTBOX_TYPE_1 0
#define GIFTBOX_TYPE_2 1
#define GIFTBOX_TYPE_3 2

class CGiftBox : public CGameObject {
	int type;
public:
	CGiftBox(float x, float y, int state , int type) : CGameObject(x, y) { 
		this->state = state; 
		this->type = type;
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void SetState(int state);
	float GetX() { return x; }
	float GetY() { return y; }
	int GetType() { return type; }	
};