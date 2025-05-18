#include "Bullet.h"
#include "Mario.h"

CBullet::CBullet(float x, float y, float vx , float vy) : CGameObject(x, y)
{
    this->vx = vx;
    this->vy = vy;
	this->ax = 0;
	this->ay = 0;
    bornTime = GetTickCount64();
}
void CBullet::OnNoCollision(DWORD dt) {
    x += vx * dt;
    y += vy * dt;
}

void CBullet::OnCollisionWith(LPCOLLISIONEVENT e) {
    // Chỉ xử lý khi đụng trúng Mario
    if (!dynamic_cast<CMario*>(e->obj))
        return;

    isDeleted = true;
}
void CBullet::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
    vx += ax * dt;
    vy += ay * dt;

    if (GetTickCount64() - bornTime > BULLET_TIMEOUT) {
        isDeleted = true;
    }

    CGameObject::Update(dt, coObjects);

    // Lọc lại danh sách, chỉ lấy Mario
    vector<LPGAMEOBJECT> filtered;
    for (auto obj : *coObjects) {
        if (dynamic_cast<CMario*>(obj)) {
            filtered.push_back(obj);
            break;
        }
    }

    CCollision::GetInstance()->Process(this, dt, &filtered);
}


void CBullet::Render()
{
    CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_BULLET)->Render(x, y);
	//RenderBoundingBox();
}

void CBullet::GetBoundingBox(float& l, float& t, float& r, float& b)
{
    l = x - BULLET_BBOX_WIDTH / 2;
    t = y - BULLET_BBOX_HEIGHT / 2;
    r = l + BULLET_BBOX_WIDTH;
    b = t + BULLET_BBOX_HEIGHT;
}
