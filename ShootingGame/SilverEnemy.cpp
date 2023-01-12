#include "SilverEnemy.h"
#include "DxLib.h"
#include <math.h>

SilverEnemy::SilverEnemy(float _speed, float _radius, int _point, int _hp) {
	enemyType = ENEMY_TYPE::SILVER;

	std::vector<float> bulletAngle = { 45.0f, 90.0f, 135.0f, 225.0f, 315.0f };

	moveDirections.push_back(MOVE_TYPE::DOWN_LEFT);
	moveDirections.push_back(MOVE_TYPE::DOWN);
	moveDirections.push_back(MOVE_TYPE::DOWN_RIGHT);
	moveDirections.push_back(MOVE_TYPE::UP_LEFT);
	moveDirections.push_back(MOVE_TYPE::UP_RIGHT);

	Initialize(moveX, moveY, _speed, _radius, _point, _hp, bulletAngle, 6.0f, 3);

	MOVE_TYPE move = moveDirections[GetRand(2)];
	ChangeMove(move);
}

void SilverEnemy::ChangeMode() {
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