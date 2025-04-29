#pragma once 
#include "GameObject.h"   
#define KOOPAS_GRAVITY 0.002f 
#define KOOPAS_WALKING_SPEED 0.05f   
#define KOOPAS_BBOX_WIDTH 17 
#define KOOPAS_BBOX_HEIGHT 26 
#define KOOPAS_BBOX_HEIGHT_SHELL 16 
#define KOOPAS_BBOX_HEIGHT_DIE 7   

class CFallsensor : public CGameObject { 
	protected: 	
		float ax; 	
		float ay;   	

		virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom); 	  	
		virtual int IsCollidable() { return 1; }; 	
		virtual int IsBlocking() { return 0; } 	
		virtual void OnNoCollision(DWORD dt);  	
		virtual void OnCollisionWith(LPCOLLISIONEVENT e);
	public: 	
		virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects); 	
		virtual void Render(); 	CFallsensor(float x, float y); 	
		void setSpeed(float vx) { this->vx = vx; } 
		float GetVy() { return this->vy; }
}; 
