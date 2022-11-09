#include "EnemyBullet.h"
#include "DxLib.h"
#include <math.h>

EnemyBullet::EnemyBullet() {};

EnemyBullet::EnemyBullet(float _x, float _y, int _bulletAngle, float _speed, int _damage, unsigned int _color) {
	x = _x;
	y = _y;
	float rad = (float)(_bulletAngle) * ((DX_PI_F * 2) / 360.0f);
	moveX = cosf(rad);
	moveY = sinf(rad);
	speed = _speed;
	damage = _damage;
	color = _color;
	SetRadius(RADIUS);
	isActive = true;
}

void EnemyBullet::Update() {
	x += moveX * speed;
	y += moveY * speed;
	Location pos = { x, y };
	SetLocation(pos);
	if (x < 0 || x > 640 || y < 0 || y > 480) Disabled();
}

void EnemyBullet::Draw() const {
	DrawCircle(x, y, RADIUS, color, TRUE);
}