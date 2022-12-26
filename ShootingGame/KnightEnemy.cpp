#include "KnightEnemy.h"
#include "DxLib.h"
#include <math.h>

KnightEnemy::KnightEnemy(float _speed, float _radius, int _point, int _hp) {
	images[0] = GetImage(2, 0);
	enemyType = ENEMY_TYPE::KNIGHT;

	int randX = GetRand(8);
	float x = (640.0f / 9.0f) * (float)randX + 20.0f;

	for (int i = 0; i < 5; i++) {
		changeMovedFlag[i] = false;
	}

	std::vector<float> bulletAngle = { 60, 120 };

	float moveX = 0.0f;
	float moveY = sinf(120.0f * (DX_PI_F / 180.0f));
	int moveType = GetRand(1);
	if (moveType == 0) {
		if (x - 40.0f > 40.0f) {
			moveX = cosf(120.0f * (DX_PI_F / 180.0f));
		}
		else {
			moveX = cosf(60.0f * (DX_PI_F / 180.0f));
		}
	}
	else {
		if (x + 40.0f < 600.0f) {
			moveX = cosf(60.0f * (DX_PI_F / 180.0f));
		}
		else {
			moveX = cosf(120.0f * (DX_PI_F / 180.0f));
		}
	}

	Initialize(x, moveX, moveY, _speed, _radius, _point, _hp, bulletAngle, 10.0f, 3);
}

void KnightEnemy::Update() {
	float newMoveX = moveX;
	int indexY = floorf(y / (480.0f / 4.5f));
	if (!changeMovedFlag[indexY]) {
		changeMovedFlag[indexY] = true;
		int newMoveType = GetRand(1);
		if (newMoveType == 0) {
			if (x - 40.0f > 40.0f) {
				newMoveX = cosf(120.0f * (DX_PI_F / 180.0f));
			}
			else {
				newMoveX = cosf(60.0f * (DX_PI_F / 180.0f));
			}
		}
		else {
			if (x + 40.0f < 600.0f) {
				newMoveX = cosf(60.0f * (DX_PI_F / 180.0f));
			}
			else {
				newMoveX = cosf(120.0f * (DX_PI_F / 180.0f));
			}
		}
		ChangeMove(newMoveX, moveY);
	}
	Enemy::Update();
}