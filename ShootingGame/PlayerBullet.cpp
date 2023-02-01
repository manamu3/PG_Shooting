#include "PlayerBullet.h"
#include "DxLib.h"
#include <math.h>

PlayerBullet::PlayerBullet(float _x, float _y, float _speed, int _damage, unsigned int _color, Enemy** _enemy, int _enemyMax, bool _isHoming) {
	x = _x;
	y = _y;
	moveX = 0;
	moveY = -1;
	speed = _speed;
	damage = _damage;
	color = _color;
	isHoming = false;
	if (_isHoming && _enemyMax > 0) {
		float min = -1;
		for (int i = 0; i < _enemyMax; i++) {
			Location enemyPos = _enemy[i]->GetLocation();
			float diffX = enemyPos.x - x;
			float diffY = enemyPos.y - y;
			float distance = sqrtf(diffX * diffX + diffY * diffY);
			if (min > distance || min < 0) {
				min = distance;
				targetEnemy = _enemy[i];
			}
		}
		isHoming = true;
	}

	SetRadius(RADIUS);
	isActive = true;
}

PlayerBullet::PlayerBullet(float _x, float _y, float _mx, float _my, float _speed, int _damage, unsigned int _color) {
	x = _x;
	y = _y;
	moveX = _mx;
	moveY = _my;
	speed = _speed;
	damage = _damage;
	color = _color;
	SetRadius(RADIUS);
	isActive = true;
}

void PlayerBullet::Update() {
	if (isHoming) {
		if (targetEnemy->HpCheck()) {
			isHoming = false;
		}
		else {
			Location enemyPos = targetEnemy->GetLocation();
			double rad = atan2(enemyPos.y - y, enemyPos.x - x);
			moveX = cos(rad);
			moveY = sin(rad);
		}
	}
	x += moveX * speed;
	y += moveY * speed;
	Location pos = { x, y };
	SetLocation(pos);
	if (x < 0 || x > 640 || y < 0 || y > 480) Disabled();
}

void PlayerBullet::Draw() const {
	DrawCircle(x, y, RADIUS, color, TRUE);
}