#include "LanceEnemy.h"
#include "DxLib.h"

LanceEnemy::LanceEnemy(float _speed, float _radius, int _point, int _hp) {
	enemyType = ENEMY_TYPE::LANCE;

	std::vector<float> bulletAngle = { 90 };

	moveDirections.push_back(MOVE_TYPE::DOWN);

	Initialize(0.0f, 1.0f, _speed, _radius, _point, _hp, bulletAngle, 6.0f, 3);
}

void LanceEnemy::ChangeMode() {
	if (enemyMode != 1) {
		enemyMode = 1;
		moveDirections.clear();
		moveDirections.push_back(MOVE_TYPE::DOWN_LEFT);
		moveDirections.push_back(MOVE_TYPE::DOWN);
		moveDirections.push_back(MOVE_TYPE::DOWN_RIGHT);
		moveDirections.push_back(MOVE_TYPE::LEFT);
		moveDirections.push_back(MOVE_TYPE::RIGHT);
		moveDirections.push_back(MOVE_TYPE::UP);
	}
}