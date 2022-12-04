#include "KnightEnemy.h"
#include "DxLib.h"
#include <math.h>

KnightEnemy::KnightEnemy(float _speed, float _radius, int _point, int _hp) {
	images[0] = GetImage(2, 0);

	int randX = GetRand(8);
	float x = (640.0f / 9.0f) * (float)randX + 20.0f;

	for (int i = 0; i < 9; i++) {
		changeMovedFlag[i] = false;
	}

	std::vector<float> bulletAngle = { 60, 120 };

	float newMoveX = 0.0f;
	float newMoveY = sin(120.0f * (DX_PI_F / 180.0f));
	int newMoveType = GetRand(1);
	if (newMoveType == 0) {
		newMoveX = cos(120.0f * (DX_PI_F / 180.0f));
	}
	else {
		newMoveX = cos(60.0f * (DX_PI_F / 180.0f));
	}

	Initialize(x, newMoveX, newMoveY, _speed, _radius, _point, _hp, bulletAngle, 10.0f, 3);
}

void KnightEnemy::Update() {
	//float y = (480.0f / 9.0f) * (float)randX + 20.0f;
	float newMoveX = moveX;
	int indexY = floorf(y / (480.0f / 4.5f));
	if (!changeMovedFlag[indexY]) {
		changeMovedFlag[indexY] = true;
		int newMoveType = GetRand(1);
		if (newMoveType == 0 && x - 40.0f > 40.0f) {
			newMoveX = cos(120.0f * (DX_PI_F / 180.0f));
		}
		else {
			newMoveX = cos(60.0f * (DX_PI_F / 180.0f));
			if (x + 40.0f > 600.0f) {
				newMoveX = cos(120.0f * (DX_PI_F / 180.0f));
			}
		}
		ChangeMove(newMoveX, moveY);
	}
	Enemy::Update();
}