#include "RookEnemy.h"
#include "DxLib.h"
#include <math.h>

RookEnemy::RookEnemy(float _speed, float _radius, int _point, int _hp) {
	images[0] = GetImage(6, 0);

	int randX = GetRand(8);
	float x = (640.0f / 9.0f) * (float)randX + 20.0f;

	backPosY = 0.0f;
	backMoveFlag = false;
	for (int i = 0; i < 9; i++) {
		changeMovedFlag[i] = false;
	}

	std::vector<float> bulletAngle = { 0.0f, 90.0f, 180.0f, 270.0f };

	float moveX = 0.0f;
	float moveY = 1.0f;

	Initialize(x, moveX, moveY, _speed, _radius, _point, _hp, bulletAngle, 10.0f, 3);
}

void RookEnemy::Update() {
	float newMoveX = moveX;
	float newMoveY = moveY;
	int indexY = 0;
	if (backMoveFlag) {
		if (backPosY > y) {
			indexY = floorf(y / (480.0f / 9.0f));
			backMoveFlag = false;
		}
	}
	else if (sideMoveFlag) {
		if ((sideMoveType == 0 && sidePosX < x) || (sideMoveType == 1 && sidePosX > x)) {
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
			newMoveType = 1;
		}
		if (newMoveType == 0) {
			newMoveX = 0.0f;
			newMoveY = -1.0f;
			backMoveFlag = true;
			backPosY = y - 40.0f;
			if (indexY - 1 >= 0) {
				changeMovedFlag[indexY - 1] = false;
			}
			changeMovedFlag[indexY] = false;
		}
		else if (newMoveType == 1) {
			newMoveX = 0.0f;
			newMoveY = 1.0f;
		}
		else if (newMoveType == 2) {
			if (x - 80.0f > 40.0f) {
				newMoveX = -1.0f;
				sideMoveType = 1;
				sidePosX = x - 80.0f;
			}
			else {
				newMoveX = 1.0f;
				sideMoveType = 0;
				sidePosX = x + 80.0f;
			}
			newMoveY = 0.0f;
			sideMoveFlag = true;
			changeMovedFlag[indexY] = false;
		}
		else if (newMoveType == 3) {
			if (x + 80.0f < 600.0f) {
				newMoveX = 1.0f;
				sideMoveType = 0;
				sidePosX = x + 80.0f;
			}
			else {
				newMoveX = -1.0f;
				sideMoveType = 1;
				sidePosX = x - 80.0f;
			}
			newMoveY = 0.0f;
			sideMoveFlag = true;
			changeMovedFlag[indexY] = false;
		}
		if (newMoveType > 1) {
			
		}
		ChangeMove(newMoveX, newMoveY);
	}
	Enemy::Update();
}
