//#pragma once
//#include "GameObject.h"
//
//class CPhysicalObject : public CGameObject {
//protected:
//    float ax, ay; // Acceleration
//    bool isRemovable;
//
//public:
//    CPhysicalObject(float x = 0, float y = 0, float vx = 0, float vy = 0, float ax = 0, float ay = 0, DirectionXAxisType nx = DirectionXAxisType::Left)
//        : CGameObject(x, y, vx, vy, nx), ax(ax), ay(ay), isRemovable(false) {
//    }
//
//    virtual void Update(DWORD dt, vector<LPPHYSICALOBJECT>* coObjects) = 0;
//
//    virtual bool GetRemovable() { return isRemovable; }
//    virtual void SetRemovable(bool removable) { isRemovable = removable; }
//
//    virtual void ResetState() = 0;
//};
