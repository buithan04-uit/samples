#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"


#define HIDE_BBOX_WIDTH 15
#define HIDE_BBOX_HEIGHT 300

class CHideBox : public CGameObject {
public:
	CHideBox(float x, float y) : CGameObject(x, y) { }
	void Render();
	void Update(DWORD dt) {}
	virtual int IsCollidable() { return 1; };
	int IsBlocking() override { return 0; }
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};