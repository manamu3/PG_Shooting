#include "PawnEnemy.h"
#include "DxLib.h"

bool PawnEnemy::pawnActive[9];

PawnEnemy::PawnEnemy(float _speed, float _radius, int _point, int _hp) {
	images[0] = GetImage(0, 0);

	randX = GetRand(8);
	if (pawnActive[randX]) {
		bool newPawn = false;
		for (int i = 0; i < 9; i++) {
			if (!pawnActive[i]) {
				newPawn = true;
				break;
			}
		}
		if (!newPawn) {
			isActive = false;
			return;
		}
	}
	while (pawnActive[randX]) {
		randX = GetRand(8);
	}
	pawnActive[randX] = true;
	float x = (640.0f / 9.0f) * (float)randX + 20.0f;

	std::vector<float> bulletAngle = { 90 };

	Initialize(x, 0.0f, 1.0f, _speed, _radius, _point, _hp, bulletAngle, 5.0f, 3);
}

void PawnEnemy::Update() {
	Enemy::Update();
	if (!isActive) {
		pawnActive[randX] = false;
	}
}