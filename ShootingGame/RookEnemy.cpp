#include "RookEnemy.h"
#include "DxLib.h"
#include <math.h>

RookEnemy::RookEnemy(float _speed, float _radius, int _point, int _hp) {
	images[0] = GetImage(6, 0);
	enemyType = ENEMY_TYPE::ROOK;

	int randX = GetRand(8);
	float x = (640.0f / 9.0f) * (float)randX + 20.0f;

	backPosY = 0.0f;
	backMoveFlag = false;
	for (int i = 0; i < 9; i++) {
		changeMovedFlag[i] = false;
	}

	std::vector<float> bulletAngle = { 0.0f, 90.0f, 180.0f, 270.0f };

	Initialize(x, 0.0f, 1.0f, _speed, _radius, _point, _hp, bulletAngle, 10.0f, 3);
}

void RookEnemy::Update() {
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
	if (!changeMovedFlag[indexY]) {
		changeMovedFlag[indexY] = true;
		int newMoveType = GetRand(3);
		if (newMoveType > 2 && y - 40.0f < 40) {
			newMoveType = GetRand(2);
		}
		MOVE_TYPE moveDirection = moveDirections[newMoveType];
		ChangeMove(&moveDirection);

		if (moveDirection == MOVE_TYPE::UP) {
			backMoveFlag = true;
			backPosY = y - 40.0f;
			if (indexY - 1 >= 0) {
				changeMovedFlag[indexY - 1] = false;
			}
			changeMovedFlag[indexY] = false;
		}
		else if (moveDirection == MOVE_TYPE::LEFT || moveDirection == MOVE_TYPE::RIGHT) {
			sidePosX = 80.0f * moveX + x;
			sideMoveFlag = true;
			changeMovedFlag[indexY] = false;
		}
	}
	Enemy::Update();
}
