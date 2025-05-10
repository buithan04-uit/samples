#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "debug.h"
#include "BoxColilsion.h"

#define BOX_TYPE_1 1
#define BOX_TYPE_1 2
#define BOX_TYPE_1 3
#define BOX_TYPE_1 4
#define BOX_TYPE_1 5

#define ID_ANI_BOX_1 70011
#define ID_ANI_BOX_2 70012
#define ID_ANI_BOX_3 70013
#define ID_ANI_BOX_4 70014
#define ID_ANI_BOX_5 70015


#define BOX_1_WIDTH 87
#define BOX_1_BBOX_WIDTH 87
#define BOX_1_BBOX_HEIGHT 79

#define BOX_2_WIDTH 215
#define BOX_2_BBOX_WIDTH 215
#define BOX_2_BBOX_HEIGHT 111

#define BOX_3_WIDTH 87
#define BOX_3_BBOX_WIDTH 87
#define BOX_3_BBOX_HEIGHT 39

#define BOX_4_WIDTH 183
#define BOX_4_BBOX_WIDTH 183
#define BOX_4_BBOX_HEIGHT 95

#define BOX_5_WIDTH 87
#define BOX_5_BBOX_WIDTH 87
#define BOX_5_BBOX_HEIGHT 143

class CBox : public CGameObject {
protected:
	int type; 
public:
	CBox(float x, float y, int type);
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() override { return 0; }
};