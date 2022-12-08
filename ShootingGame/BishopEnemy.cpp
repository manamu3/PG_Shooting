#include "BishopEnemy.h"
#include "DxLib.h"
#include <math.h>

BishopEnemy::BishopEnemy(float _speed, float _radius, int _point, int _hp) {
	images[0] = GetImage(5, 0);

	int randX = GetRand(8);
	float x = (640.0f / 9.0f) * (float)randX + 20.0f;

	backPosY = 0.0f;
	backMoveFlag = false;
	for (int i = 0; i < 9; i++) {
		changeMovedFlag[i] = false;
	}

	std::vector<float> bulletAngle = { 45.0f, 135.0f, 225.0f, 315.0f };

	float moveX = 0.0f;
	float moveY = 0.0f;
	int moveType = GetRand(1);
	if (moveType == 0) {
		if (x - 40.0f > 40.0f) {
			moveX = cosf(135.0f * (DX_PI_F / 180.0f));
		}
		else {
			moveX = cosf(45.0f * (DX_PI_F / 180.0f));
		}
		moveY = sinf(135.0f * (DX_PI_F / 180.0f));
	}
	else if (moveType == 1) {
		if (x + 40.0f < 600.0f) {
			moveX = cosf(45.0f * (DX_PI_F / 180.0f));
		}
		else {
			moveX = cosf(135.0f * (DX_PI_F / 180.0f));
		}
		moveY = sinf(135.0f * (DX_PI_F / 180.0f));
	}

	Initialize(x, moveX, moveY, _speed, _radius, _point, _hp, bulletAngle, 10.0f, 3);
}

void BishopEnemy::Update() {
	float newMoveX = moveX;
	float newMoveY = moveY;
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
		if (newMoveType > 2 && y - 40.0f < 40) {
			newMoveType = GetRand(1);
		}
		if (newMoveType == 0) {
			if (x - 40.0f > 40.0f) {
				newMoveX = cosf(135.0f * (DX_PI_F / 180.0f));
			}
			else {
				newMoveX = cosf(45.0f * (DX_PI_F / 180.0f));
			}
			newMoveY = sinf(135.0f * (DX_PI_F / 180.0f));
		}
		else if (newMoveType == 1) {
			if (x + 40.0f < 600.0f) {
				newMoveX = cosf(45.0f * (DX_PI_F / 180.0f));
			}
			else {
				newMoveX = cosf(135.0f * (DX_PI_F / 180.0f));
			}
			newMoveY = sinf(135.0f * (DX_PI_F / 180.0f));
		}
		else if (newMoveType == 2) {
			if (x - 40.0f > 40.0f) {
				newMoveX = cosf(225.0f * (DX_PI_F / 180.0f));
			}
			else {
				newMoveX = cosf(315.0f * (DX_PI_F / 180.0f));
			}
			newMoveY = sinf(225.0f * (DX_PI_F / 180.0f));
		}
		else if (newMoveType == 3) {
			if (x + 40.0f < 600.0f) {
				newMoveX = cosf(315.0f * (DX_PI_F / 180.0f));
			}
			else {
				newMoveX = cosf(225.0f * (DX_PI_F / 180.0f));
			}
			newMoveY = sinf(225.0f * (DX_PI_F / 180.0f));
		}
		if (newMoveType > 1) {
			backMoveFlag = true;
			backPosY = y - 40.0f;
			if (indexY - 1 >= 0) {
				changeMovedFlag[indexY - 1] = false;
			}
			changeMovedFlag[indexY] = false;
		}
		ChangeMove(newMoveX, newMoveY);
	}
	Enemy::Update();
}