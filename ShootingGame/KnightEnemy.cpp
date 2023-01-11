#include "KnightEnemy.h"
#include "DxLib.h"
#include <math.h>

KnightEnemy::KnightEnemy(float _speed, float _radius, int _point, int _hp) {
	enemyType = ENEMY_TYPE::KNIGHT;

	std::vector<float> bulletAngle = { 60, 120 };

	Initialize(0.0f, 0.0f, _speed, _radius, _point, _hp, bulletAngle, 10.0f, 3);
	MOVE_TYPE moveDirection = moveDirections[GetRand(1)];
	ChangeMove(moveDirection);
}