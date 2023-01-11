#include "RookEnemy.h"
#include "DxLib.h"
#include <math.h>

RookEnemy::RookEnemy(float _speed, float _radius, int _point, int _hp) {
	enemyType = ENEMY_TYPE::ROOK;

	std::vector<float> bulletAngle = { 0.0f, 90.0f, 180.0f, 270.0f };

	Initialize(0.0f, 1.0f, _speed, _radius, _point, _hp, bulletAngle, 10.0f, 3);
}