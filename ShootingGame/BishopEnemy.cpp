#include "BishopEnemy.h"
#include "DxLib.h"
#include <math.h>

BishopEnemy::BishopEnemy(float _speed, float _radius, int _point, int _hp) {
	images[0] = GetImage(5, 0);
	enemyType = ENEMY_TYPE::BISHOP;

	int randX = GetRand(8);
	float x = (640.0f / 9.0f) * (float)randX + 20.0f;

	backPosY = 0.0f;
	backMoveFlag = false;
	for (int i = 0; i < 9; i++) {
		changeMovedFlag[i] = false;
	}

	std::vector<float> bulletAngle = { 45.0f, 135.0f, 225.0f, 315.0f };

	MOVE_TYPE move = moveDirections[GetRand(1)];
	ChangeMove(&move);

	Initialize(x, moveX, moveY, _speed, _radius, _point, _hp, bulletAngle, 10.0f, 3);
}

void BishopEnemy::Update() {
	int indexY = 0;
	if (backMoveFlag) {
		if (backPosY > y) {
			indexY = floorf(y / (480.0f / 9.0f));
			backMoveFlag = false;
		}
	}
	else {
		indexY = floorf(y / (480.0f / 9.0f));
	}
	if (!changeMovedFlag[indexY]) {
		changeMovedFlag[indexY] = true;
		int newMoveType = GetRand(3);
		if (newMoveType > 1 && y - 40.0f < 40) {
			newMoveType = GetRand(1);
		}
		MOVE_TYPE moveDirection = moveDirections[newMoveType];
		ChangeMove(&moveDirection);

		if (moveDirection == MOVE_TYPE::UP_LEFT || moveDirection == MOVE_TYPE::UP_RIGHT) {
			backMoveFlag = true;
			backPosY = y - 40.0f;
			if (indexY - 1 >= 0) {
				changeMovedFlag[indexY - 1] = false;
			}
			changeMovedFlag[indexY] = false;
		}
	}
	Enemy::Update();
}