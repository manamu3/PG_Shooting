#include "Bullet.h"
#include "DxLib.h"

void Bullet::Initialize(float _x, float _y, float _moveX, float _moveY, float _speed, int _damage, unsigned int _color) {
	x = _x;
	y = _y;
	moveX = _moveX;
	moveY = _moveY;
	speed = _speed;
	damage = _damage;
	color = _color;
	isEnable = true;
}

void Bullet::Update() {
	x += moveX * speed;
	y += moveY * speed;
	if (y < 0) isEnable = false;
	else if (y > 500) isEnable = false;
	if (x < 0) isEnable = false;
	else if (x > 640) isEnable = false;
}

void Bullet::Draw() const {
	DrawCircle(x, y, RADIUS, color, TRUE);
}