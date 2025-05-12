#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_STAR_1 80011
#define ID_ANI_STAR_2 80012
#define ID_ANI_STAR_3 80013



#define STAR_1_WIDTH 31
#define STAR_1_BBOX_WIDTH 31
#define STAR_1_BBOX_HEIGHT 22

#define STAR_2_WIDTH 31
#define STAR_2_BBOX_WIDTH 31
#define STAR_2_BBOX_HEIGHT 22

#define STAR_3_WIDTH 31
#define STAR_3_BBOX_WIDTH 31
#define STAR_3_BBOX_HEIGHT 22



class CStar : public CGameObject {
	int type; 
public:
	CStar(float x, float y, int type) : CGameObject(x, y) { this->type = type; }

	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() override { return 0; }
};