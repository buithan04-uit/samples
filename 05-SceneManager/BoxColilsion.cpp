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

int CBoxCollision::IsDirectionColliable(float nx, float ny)
{
	if (nx == 0 && ny == -1) return 1;
	else return 0;
}

void CBoxCollision::Render() {
	RenderBoundingBox();
}
