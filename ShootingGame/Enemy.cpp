#include "Enemy.h"
#include "DxLib.h"
#include <math.h>

bool Enemy::pawnActive[9];

Enemy::Enemy() {
	bullets = new Bullet*[BULLET_MAX];
	for (int i = 0; i < BULLET_MAX; i++) {
		bullets[i] = nullptr;
	}
	hp = 10;
	point = 100;
	isDamage = false;
	images[0] = GetImage(0, 0);
}

void Enemy::Init(float _moveX, float _moveY, float _speed, float _radius, int _hp) {
	randX = GetRand(8);
	if (pawnActive[randX]) {
		bool newPawn = false;
		for (int i = 0; i < 9; i++) {
			if (!pawnActive[i]) {
				newPawn = true;
				break;
			}
		}
		if (!newPawn) {
			isEnable = false;
			return;
		}
	}
	while (pawnActive[randX]) {
		randX = GetRand(8);
	}
	pawnActive[randX] = true;
	float x = (640.0f / 9.0f) * (float)randX + 20.0f;
	CharaBase::Init(x, 0, _moveX, _moveY, _speed, _radius);
	hp = _hp;
}

void Enemy::Update() {
	if (isEnable) {
		y += moveY * speed;
		Location nowLocation = { x, y };
		SetLocation(nowLocation);
		if (y > 480) {
			isEnable = false;
			pawnActive[randX] = false;
		}
		if (--bulletTime <= 0) {
			bool shotBullet = false;
			for (int i = 0; i < BULLET_MAX; i++) {
				if (bullets[i] == nullptr) {
					bullets[i] = new Bullet(x, y, 0, 1, 5, 3, 0xFFFF00);
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
		if (bullets[i] != nullptr) {
			bullets[i]->Update();
		}
	}
}

void Enemy::Draw() const {
	if (isEnable) {
		DrawGraph(x - 20, y - 20, images[0], TRUE);
	}
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullets[i] != nullptr) {
			bullets[i]->Draw();
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
	if (HpCheck()) {
		isEnable = false;
		pawnActive[randX] = false;
	}
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