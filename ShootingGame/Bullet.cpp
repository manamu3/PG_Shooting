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
	SetRadius(RADIUS);
	isEnable = true;
}

void Bullet::Update() {
	x += moveX * speed;
	y += moveY * speed;
	Location pos = { x, y };
	SetLocation(pos);
	if (x < 0 || x > 640) isEnable = false;
	if (y < 0 || y > 480) isEnable = false;
}

void Bullet::Draw() const {
	DrawCircle(x, y, RADIUS, color, TRUE);
}