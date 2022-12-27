#include "KnightEnemy.h"
#include "DxLib.h"
#include <math.h>

KnightEnemy::KnightEnemy(float _speed, float _radius, int _point, int _hp) {
	enemyType = ENEMY_TYPE::KNIGHT;

	for (int i = 0; i < 5; i++) {
		changeMovedFlag[i] = false;
	}

	std::vector<float> bulletAngle = { 60, 120 };

	float moveX = 0.0f;
	float moveY = sinf(120.0f * (DX_PI_F / 180.0f));
	GetNextMove(moveX);

	Initialize(moveX, moveY, _speed, _radius, _point, _hp, bulletAngle, 10.0f, 3);
}

void KnightEnemy::Update() {
	int indexY = floorf(y / (480.0f / 4.5f));
	if (!changeMovedFlag[indexY] || ScreenOut()) {
		changeMovedFlag[indexY] = true;
		float newMoveX;
		GetNextMove(newMoveX);
		ChangeMove(newMoveX, moveY);
	}
	Enemy::Update();
}

void KnightEnemy::GetNextMove(float& moveX) {
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
}