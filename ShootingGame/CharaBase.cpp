#include "CharaBase.h"

void CharaBase::Init(float _x, float _y, float _moveX, float _moveY, float _speed, float _radius) {
	x = _x;
	y = _y;
	moveX = _moveX;
	moveY = _moveY;
	speed = _speed;
	SetRadius(_radius);
	isActive = true;
	bulletCount = 0;
}

BulletsBase** CharaBase::GetBullets() {
	return bullets;
}

void CharaBase::DeleteBullet(int& i) {
	bulletCount--;
	BulletsBase* bullet = bullets[i];
	bullets[i] = bullets[bulletCount];
	bullets[bulletCount] = bullet;
	delete bullets[bulletCount];
	bullets[bulletCount] = nullptr;
	i--;
}