#include "CharaBase.h"

void CharaBase::Init(float _x, float _y, float _moveX, float _moveY, float _speed, float _radius) {
	x = _x;
	y = _y;
	moveX = _moveX;
	moveY = _moveY;
	speed = _speed;
	SetRadius(_radius);
	isActive = true;
}

BulletsBase** CharaBase::GetBullets() {
	return bullets;
}

bool CharaBase::IsActive() {
	return isActive;
}