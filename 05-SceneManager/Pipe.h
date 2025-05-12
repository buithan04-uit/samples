#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_PIPE_1 60000
#define ID_ANI_PIPE_2 60001
#define ID_ANI_PIPE_3 60002
#define ID_ANI_PIPE_4 60003



#define PIPE_1_WIDTH 31
#define PIPE_1_BBOX_WIDTH 31
#define PIPE_1_BBOX_HEIGHT 47

#define PIPE_2_WIDTH 31
#define PIPE_2_BBOX_WIDTH 31
#define PIPE_2_BBOX_HEIGHT 32

#define PIPE_3_WIDTH 29
#define PIPE_3_BBOX_WIDTH 29
#define PIPE_3_BBOX_HEIGHT 33

#define PIPE_4_WIDTH 31
#define PIPE_4_BBOX_WIDTH 31
#define PIPE_4_BBOX_HEIGHT 192



class CPipe : public CGameObject {
public:
	CPipe(float x, float y , int state) : CGameObject(x, y) {
		this->state = state;	
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};