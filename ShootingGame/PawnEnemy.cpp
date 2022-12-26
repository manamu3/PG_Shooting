#include "PawnEnemy.h"
#include "DxLib.h"

PawnEnemy::PawnEnemy(float _x, float _speed, float _radius, int _point, int _hp) {
	images[0] = GetImage(0, 0);
	enemyType = ENEMY_TYPE::PAWN;

	std::vector<float> bulletAngle = { 90 };

	Initialize(_x, 0.0f, 1.0f, _speed, _radius, _point, _hp, bulletAngle, 5.0f, 3);
}

void PawnEnemy::Update() {
	Enemy::Update();
}