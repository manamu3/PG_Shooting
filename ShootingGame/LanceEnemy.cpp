#include "LanceEnemy.h"
#include "DxLib.h"

LanceEnemy::LanceEnemy(float _speed, float _radius, int _point, int _hp) {
	images[0] = GetImage(1, 0);

	int randX = GetRand(8);
	float x = (640.0f / 9.0f) * (float)randX + 20.0f;

	std::vector<float> bulletAngle = { 90 };

	Initialize(x, 0.0f, 1.0f, _speed, _radius, _point, _hp, bulletAngle, 10.0f, 3);
}

void LanceEnemy::Update() {
	Enemy::Update();
}