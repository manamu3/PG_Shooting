#include "PawnEnemy.h"
#include "DxLib.h"

bool PawnEnemy::pawnActive[9];

PawnEnemy::PawnEnemy() {

}

PawnEnemy::PawnEnemy(float _moveX, float _moveY, float _speed, float _radius, int _point, int _hp) {
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

	Initialize(x, _moveX, _moveY, _speed, _radius, _point, _hp);
}

void PawnEnemy::Update() {
	Enemy::Update();
	if (!isActive) {
		pawnActive[randX] = false;
	}
}

void PawnEnemy::Draw() const {
	Enemy::Draw();
}