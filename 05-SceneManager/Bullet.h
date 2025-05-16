
#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define BULLET_SPEED         0.1f

#define BULLET_BBOX_WIDTH    7
#define BULLET_BBOX_HEIGHT   7

#define BULLET_TIMEOUT   5000

#define ID_ANI_BULLET 100011

class CBullet : public CGameObject
{
protected:
    float ax;
    float ay;
    ULONGLONG bornTime;
    virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
    virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
    virtual void Render();

    virtual int IsCollidable() { return 1; };
    virtual int IsBlocking() { return 0; }
    virtual void OnNoCollision(DWORD dt);

    virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
    CBullet(float x, float y, float vx , float vy);
};
