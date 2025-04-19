#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_CLOUD_SMALL 40011
#define ID_ANI_CLOUD_MEDIUM 40012
#define ID_ANI_CLOUD_LARGE 40013
#define ID_ANI_CLOUD_MINI 40014


#define CLOUD_SMALL_WIDTH 31
#define CLOUD_SMALL_BBOX_WIDTH 31
#define CLOUD_SMALL_BBOX_HEIGHT 22

#define CLOUD_MEDIUM_WIDTH 47
#define CLOUD_MEDIUM_BBOX_WIDTH 47
#define CLOUD_MEDIUM_BBOX_HEIGHT 22

#define CLOUD_LARGE_WIDTH 47
#define CLOUD_LARGE_BBOX_WIDTH 47
#define CLOUD_LARGE_BBOX_HEIGHT 22

#define CLOUD_MINI_WIDTH 15
#define CLOUD_MINI_BBOX_WIDTH 15
#define CLOUD_MINI_BBOX_HEIGHT 15

class CCloud : public CGameObject {
	int type; // 0: small, 1: medium, 2: large , 3: mini
public:
	CCloud(float x, float y, int type) : CGameObject(x, y) { this->type  = type;}

	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() override { return 0; }
};