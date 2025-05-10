#pragma once 
#include "GameObject.h"   



class CBoxCollision : public CGameObject {
protected:
	float ax;
	float ay;
	int BoxWidth;
	int BoxHeight;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 1; }


public:
	void Update(DWORD dt) {}
	virtual void Render(); 
	CBoxCollision(float x, float y, int BoxWidth, int BoxHeight);


};
