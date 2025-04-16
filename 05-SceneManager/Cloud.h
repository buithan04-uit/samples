#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_CLOUD_SMALL 40001
#define ID_ANI_CLOUD_MEDIUM 40002
#define ID_ANI_CLOUD_LARGE 40003

#define CLOUD_SMALL_WIDTH 34
#define CLOUD_SMALL_BBOX_WIDTH 34
#define CLOUD_SMALL_BBOX_HEIGHT 24

#define CLOUD_MEDIUM_WIDTH 50
#define CLOUD_MEDIUM_BBOX_WIDTH 50
#define CLOUD_MEDIUM_BBOX_HEIGHT 24

#define CLOUD_LARGE_WIDTH 50
#define CLOUD_LARGE_BBOX_WIDTH 50
#define CLOUD_LARGE_BBOX_HEIGHT 24

class CCloud : public CGameObject {
	int type; // 0: small, 1: medium, 2: large
public:
	CCloud(float x, float y, int type) : CGameObject(x, y) { this->type  = type;}

	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() override { return 0; }
};