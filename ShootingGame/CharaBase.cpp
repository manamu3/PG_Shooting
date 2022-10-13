#include "CharaBase.h"

void CharaBase::Init(float _x, float _y, float _moveX, float _moveY, float _speed, float _radius) {
	x = _x;
	y = _y;
	moveX = _moveX;
	moveY = _moveY;
	speed = _speed;
	SetRadius(_radius);
	isEnable = true;
}

void CharaBase::GetBullets(Bullet* _bullets) {
	_bullets = bullets;
}

bool CharaBase::IsEnable() {
	return isEnable;
}

CharaBase::~CharaBase() {
	if (bullets != nullptr) {
		delete[] bullets;
	}
}