#pragma once

#include "Coin.h"

#define COIN_BOUNCE_SPEED_Y -0.25f
#define COIN_GRAVITY 0.0009f
#define COIN_BOUNCE_LIFETIME 600 

class CBouncingCoin : public CCoin {
	DWORD startTime;

public:
	CBouncingCoin(float x, float y) : CCoin(x, y) {
		vy = COIN_BOUNCE_SPEED_Y;
		startTime = GetTickCount64();
	}

	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) override {
		vy += COIN_GRAVITY * dt;
		y += vy * dt;

		if (GetTickCount64() - startTime >= COIN_BOUNCE_LIFETIME) {
			Delete();

			// coin ++;
		}
	}
};
