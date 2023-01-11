#include "GoldEnemy.h"
#include "DxLib.h"
#include <math.h>

GoldEnemy::GoldEnemy(float _speed, float _radius, int _point, int _hp) {
	enemyType = ENEMY_TYPE::GOLD;

	std::vector<float> bulletAngle = { 0.0f, 45.0f, 90.0f, 135.0f, 180.0f, 270.0f };

	Initialize(moveX, moveY, _speed, _radius, _point, _hp, bulletAngle, 10.0f, 3);

	MOVE_TYPE move = moveDirections[GetRand(2)];
	ChangeMove(move);
}