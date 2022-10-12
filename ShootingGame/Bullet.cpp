#include "Bullet.h"
#include "DxLib.h"

Bullet::Bullet(float _x, float _y, float _moveX, float _moveY, float _speed, int _damage, unsigned int _color) {
	x = _x;
	y = _y;
	moveX = _moveX;
	moveY = _moveY;
	speed = _speed;
	damage = _damage;
	color = _color;
}

void Bullet::Update() {
	x += moveX * speed;
	y += moveY * speed;
}

void Bullet::Draw() const {
	DrawCircle(x, y, RADIUS, color, TRUE);
}