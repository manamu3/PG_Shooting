#include "PlayerBullet.h"
#include "DxLib.h"
#include <math.h>

PlayerBullet::PlayerBullet() {};

PlayerBullet::PlayerBullet(float _x, float _y, float _speed, int _damage, unsigned int _color) {
	x = _x;
	y = _y;
	moveX = 0;
	moveY = -1;
	speed = _speed;
	damage = _damage;
	color = _color;
	SetRadius(RADIUS);
	isActive = true;
}

void PlayerBullet::Update() {
	x += moveX * speed;
	y += moveY * speed;
	Location pos = { x, y };
	SetLocation(pos);
	if (x < 0 || x > 640 || y < 0 || y > 480) Disabled();
}

void PlayerBullet::Draw() const {
	DrawCircle(x, y, RADIUS, color, TRUE);
}