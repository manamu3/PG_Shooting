#include "GoldEnemy.h"
#include "DxLib.h"
#include <math.h>

GoldEnemy::GoldEnemy(float _speed, float _radius, int _point, int _hp) {
	enemyType = ENEMY_TYPE::GOLD;

	backPosY = 0.0f;
	backMoveFlag = false;
	sidePosX = 0.0f;
	sideMoveFlag = false;
	for (int i = 0; i < 9; i++) {
		changeMovedFlag[i] = false;
	}

	std::vector<float> bulletAngle = { 0.0f, 45.0f, 90.0f, 135.0f, 180.0f, 270.0f };

	MOVE_TYPE move = moveDirections[GetRand(2)];
	ChangeMove(move);

	Initialize(moveX, moveY, _speed, _radius, _point, _hp, bulletAngle, 10.0f, 3);
}

void GoldEnemy::Update() {
	int indexY = 0;
	if (backMoveFlag) {
		if (backPosY > y) {
			indexY = floorf(y / (480.0f / 9.0f));
			backMoveFlag = false;
		}
	}
	else if (sideMoveFlag) {
		if (fabsf(sidePosX - x) < speed) {
			indexY = floorf(y / (480.0f / 9.0f));
			sideMoveFlag = false;
		}
	}
	else {
		indexY = floorf(y / (480.0f / 9.0f));
	}
	if (!changeMovedFlag[indexY] || ScreenOut()) {
		sideMoveFlag = false;
		backMoveFlag = false;
		changeMovedFlag[indexY] = true;
		int newMoveType = GetRand(5);
		if (newMoveType > 4 && y - 40.0f < 40) {
			newMoveType = GetRand(4);
		}
		MOVE_TYPE moveDirection = moveDirections[newMoveType];
		ChangeMove(moveDirection);

		if (moveDirection == MOVE_TYPE::LEFT || moveDirection == MOVE_TYPE::RIGHT) {
			sidePosX = 80.0f * moveX + x;
			sideMoveFlag = true;
			changeMovedFlag[indexY] = false;
		}
		else if (moveDirection == MOVE_TYPE::UP) {
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