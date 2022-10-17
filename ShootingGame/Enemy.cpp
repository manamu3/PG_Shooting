#include "Enemy.h"
#include "DxLib.h"
#include <math.h>

Enemy::Enemy() {
	bullets = new Bullet[ENEMY_BULLET_MAX];
	hp = 10;
	point = 100;
}

void Enemy::Update() {
	if (isEnable) {
		y += moveY * speed;
		if (y > 480) {
			isEnable = false;
		}
		if (--bulletTime <= 0) {
			bool shotBullet = false;
			for (int i = 0; i < ENEMY_BULLET_MAX; i++) {
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
	for (int i = 0; i < ENEMY_BULLET_MAX; i++) {
		if (bullets[i].IsEnable()) {
			bullets[i].Update();
		}
	}
}

void Enemy::Draw() const {
	if (isEnable) {
		DrawCircle(x, y, 10, 0xFF0000, TRUE);
	}
	for (int i = 0; i < ENEMY_BULLET_MAX; i++) {
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