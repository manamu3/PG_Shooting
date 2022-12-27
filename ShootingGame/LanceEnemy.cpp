#include "LanceEnemy.h"
#include "DxLib.h"

LanceEnemy::LanceEnemy(float _speed, float _radius, int _point, int _hp) {
	enemyType = ENEMY_TYPE::LANCE;

	std::vector<float> bulletAngle = { 90 };

	Initialize(0.0f, 1.0f, _speed, _radius, _point, _hp, bulletAngle, 10.0f, 3);
}