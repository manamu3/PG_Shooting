#include "Enemy.h"
#include "DxLib.h"
#include <math.h>

Enemy::Enemy() {
	bullets = new Bullet[BULLET_MAX];
	hp = 10;
	point = 100;
	isDamage = false;
	images[0] = GetImage(0, 0);
}

void Enemy::Init(float _x, float _y, float _moveX, float _moveY, float _speed, float _radius, int _hp) {
	CharaBase::Init(_x, _y, _moveX, _moveY, _speed, _radius);
	hp = _hp;
}

void Enemy::Update() {
	if (isEnable) {
		y += moveY * speed;
		Location nowLocation = { x, y };
		SetLocation(nowLocation);
		if (y > 480) {
			isEnable = false;
		}
		if (--bulletTime <= 0) {
			bool shotBullet = false;
			for (int i = 0; i < BULLET_MAX; i++) {
				if (!bullets[i].IsEnable()) {
					bullets[i].Initialize(x, y, 0, 1, 5, 3, 0xFFFF00);
					shotBullet = true;
					break;
				}
			}
			if (shotBullet) {
				bulletTime = GetRand(ENEMY_BULLET_INTERVAL);
			}
		}
	}
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullets[i].IsEnable()) {
			bullets[i].Update();
		}
	}
}

void Enemy::Draw() const {
	if (isEnable) {
		DrawGraph(x - 20, y - 20, images[0], TRUE);
	}
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullets[i].IsEnable()) {
			bullets[i].Draw();
		}
	}
}

void Enemy::Hit(Location pos) {
	if (HitSphere(pos)) {
		isDamage = true;
	}
}

void Enemy::Damage(int damage) {
	hp -= damage;
	if (HpCheck()) isEnable = false;
	isDamage = false;
}

bool Enemy::IsDamage() {
	return isDamage;
}

bool Enemy::HpCheck() {
	return hp <= 0;
}

int Enemy::GetPoint() {
	return point;
}