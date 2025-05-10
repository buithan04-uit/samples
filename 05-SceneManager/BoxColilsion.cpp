#include "BoxColilsion.h"


CBoxCollision::CBoxCollision (float x, float y , int BoxWidth , int BoxHeight) : CGameObject(x, y) {
	this->ax = 0;
	this->ay = 0;
	this->BoxWidth = BoxWidth;
	this->BoxHeight = BoxHeight;
}

void CBoxCollision::GetBoundingBox(float& left, float& top, float& right, float& bottom) {
	left = x - BoxWidth / 2;
	top = y - BoxHeight / 2;
	right = left + BoxWidth;
	bottom = top + BoxHeight;
}



void CBoxCollision::Render() {
	RenderBoundingBox();
}
