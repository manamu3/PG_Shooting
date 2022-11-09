#include "Enemy.h"
#include "DxLib.h"
#include "EnemyBullet.h"

void Enemy::Initialize(float x, float _moveX, float _moveY, float _speed, float _radius, int _point, int _hp, std::vector<float> _bulletAngle) {
	bullets = (new BulletsBase *[BULLET_MAX]);
	for (int i = 0; i < BULLET_MAX; i++) {
		bullets[i] = nullptr;
	}
	hp = _hp;
	point = _point;
	isDamage = false;
	bulletTime = GetRand(ENEMY_BULLET_INTERVAL);
	bulletDirection = _bulletAngle;
	CharaBase::Init(x, 0, _moveX, _moveY, _speed, _radius);
}

void Enemy::Update() {
	static int bulletCnt = 0;
	if (isActive) {
		y += moveY * speed;
		Location nowLocation = { x, y };
		SetLocation(nowLocation);
		if (y > 480) {
			isActive = false;
		}
		if (--bulletTime <= 0) {
			bool shotBullet = false;
			for (int i = 0; i < BULLET_MAX; i++) {
				if (bullets[i] == nullptr) {
					bullets[i] = new EnemyBullet(x, y, bulletDirection[bulletCnt], 5, 3, 0xFFFF00);
					if (++bulletCnt >= bulletDirection.size()) {
						shotBullet = true;
						break;
					}
				}
			}
			if (shotBullet) {
				bulletTime = GetRand(ENEMY_BULLET_INTERVAL);
				bulletCnt = 0;
			}
		}
	}
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullets[i] != nullptr) {
			bullets[i]->Update();
			if (!bullets[i]->IsActive()) {
				delete bullets[i];
				bullets[i] = nullptr;
			}
		}
	}
}

void Enemy::Draw() const {
	if (isActive) {
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
		isActive = false;
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

Enemy::~Enemy() {
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullets[i] != nullptr) {
			delete bullets[i];
			bullets[i] = nullptr;
		}
	}
}