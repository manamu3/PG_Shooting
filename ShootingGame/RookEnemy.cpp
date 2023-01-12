#include "RookEnemy.h"
#include "DxLib.h"
#include <math.h>

RookEnemy::RookEnemy(float _speed, float _radius, int _point, int _hp) {
	enemyType = ENEMY_TYPE::ROOK;

	std::vector<float> bulletAngle = { 0.0f, 90.0f, 180.0f, 270.0f };

	moveDirections.push_back(MOVE_TYPE::UP);
	moveDirections.push_back(MOVE_TYPE::DOWN);
	moveDirections.push_back(MOVE_TYPE::LEFT);
	moveDirections.push_back(MOVE_TYPE::RIGHT);

	Initialize(0.0f, 1.0f, _speed, _radius, _point, _hp, bulletAngle, 6.0f, 3);
}

void RookEnemy::ChangeMode() {
	if (enemyMode != 1) {
		enemyMode = 1;
		moveDirections.clear();
		moveDirections.push_back(MOVE_TYPE::DOWN_LEFT);
		moveDirections.push_back(MOVE_TYPE::DOWN);
		moveDirections.push_back(MOVE_TYPE::DOWN_RIGHT);
		moveDirections.push_back(MOVE_TYPE::LEFT);
		moveDirections.push_back(MOVE_TYPE::RIGHT);
		moveDirections.push_back(MOVE_TYPE::UP_LEFT);
		moveDirections.push_back(MOVE_TYPE::UP);
		moveDirections.push_back(MOVE_TYPE::UP_RIGHT);
	}
}