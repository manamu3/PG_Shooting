#include "KnightEnemy.h"
#include "DxLib.h"
#include <math.h>

KnightEnemy::KnightEnemy(float _speed, float _radius, int _point, int _hp) {
	enemyType = ENEMY_TYPE::KNIGHT;

	std::vector<float> bulletAngle = { 60, 120 };

	moveDirections.push_back(MOVE_TYPE::KNIGHT_LEFT);
	moveDirections.push_back(MOVE_TYPE::KNIGHT_RIGHT);

	Initialize(0.0f, 0.0f, _speed, _radius, _point, _hp, bulletAngle, 6.0f, 3);
	MOVE_TYPE moveDirection = moveDirections[GetRand(1)];
	ChangeMove(moveDirection);
}

void KnightEnemy::ChangeMode() {
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