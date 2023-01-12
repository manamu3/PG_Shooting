#include "PawnEnemy.h"
#include "DxLib.h"

PawnEnemy::PawnEnemy(float _x, float _speed, float _radius, int _point, int _hp) {
	enemyType = ENEMY_TYPE::PAWN;

	std::vector<float> bulletAngle = { 90 };
	
	moveDirections.push_back(MOVE_TYPE::DOWN);

	Initialize(0.0f, 1.0f, _speed, _radius, _point, _hp, bulletAngle, 3.0f, 3);
	SetEnemyX(_x);
}

void PawnEnemy::ChangeMode() {
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