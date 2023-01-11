#include "SilverEnemy.h"
#include "DxLib.h"
#include <math.h>

SilverEnemy::SilverEnemy(float _speed, float _radius, int _point, int _hp) {
	enemyType = ENEMY_TYPE::SILVER;

	std::vector<float> bulletAngle = { 45.0f, 90.0f, 135.0f, 225.0f, 315.0f };

	Initialize(moveX, moveY, _speed, _radius, _point, _hp, bulletAngle, 10.0f, 3);

	MOVE_TYPE move = moveDirections[GetRand(2)];
	ChangeMove(move);
}