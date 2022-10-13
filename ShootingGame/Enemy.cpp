#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy() {
	bullets = new Bullet[100];
	hp = 10;
	point = 100;
}

void Enemy::Update() {
	y += moveY * speed;
	if (y > 500) isEnable = false;
	if (--bulletTime <= 0) {
		for (int i = 0; i < 100; i++) {
			if (!bullets[i].IsEnable()) {
				bullets[i].Initialize(x, y, 0, 1, 5, 3, 0xFFFF00);
			}
		}
		bulletTime = GetRand(ENEMY_BULLET_INTERVAL);
	}
	for (int i = 0; i < 100; i++) {
		if (bullets[i].IsEnable()) {
			bullets[i].Update();
		}
	}
}

void Enemy::Draw() const {
	DrawCircle(x, y, 10, 0xFF0000, TRUE);
	for (int i = 0; i < 100; i++) {
		if (bullets[i].IsEnable()) {
			bullets[i].Draw();
		}
	}
}

void Enemy::Hit() {

}

bool Enemy::HpCheck() {
	return hp <= 0;
}

int Enemy::GetPoint() {
	return point;
}