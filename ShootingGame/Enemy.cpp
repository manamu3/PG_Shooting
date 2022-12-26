#include "Enemy.h"
#include "DxLib.h"
#include "EnemyBullet.h"

Enemy::Enemy() {
	bullets = (new BulletsBase * [BULLET_MAX]);
	for (int i = 0; i < BULLET_MAX; i++) {
		bullets[i] = nullptr;
	}
	isDamage = false;
	bulletCount = 0;
	bulletTime = GetRand(ENEMY_BULLET_INTERVAL);
}

void Enemy::Initialize(float x, float _moveX, float _moveY, float _speed, float _radius, int _point, int _hp, std::vector<float> _bulletAngle, float _bulletSpeed, int _bulletDamage) {
	hp = _hp;
	point = _point;
	bulletDirection = _bulletAngle;
	bulletSpeed = _bulletSpeed;
	bulletDamage = _bulletDamage;
	CharaBase::Init(x, 0, _moveX, _moveY, _speed, _radius);
}

void Enemy::Update() {
	if (isActive) {
		x += moveX * speed;
		y += moveY * speed;
		Location nowLocation = { x, y };
		SetLocation(nowLocation);
		if (y > 480) {
			isActive = false;
		}
		if (--bulletTime <= 0) {
			CreateBullet();
			bulletTime = GetRand(ENEMY_BULLET_INTERVAL);
		}
	}
	for (int i = 0; i < bulletCount; i++) {
		if (bullets[i] != nullptr) {
			bullets[i]->Update();
			if (!bullets[i]->IsActive()) {
				bulletCount--;
				*bullets[i] = *bullets[bulletCount];
				delete bullets[bulletCount];
				bullets[bulletCount] = nullptr;
				i--;
			}
		}
	}
}

void Enemy::CreateBullet() {
	int count = 0;
	for (int i = bulletCount; i < BULLET_MAX; i++) {
		if (bullets[i] == nullptr) {
			bullets[i] = new EnemyBullet(x, y, bulletDirection[count], bulletSpeed, bulletDamage, 0xFFFF00);
			bulletCount++;
			if (++count >= bulletDirection.size()) {
				break;
			}
		}
	}
}

void Enemy::Draw() const {
	if (isActive) {
		DrawRotaGraphF(x, y, 1.0, 0.0, images[0], TRUE);
	}
	for (int i = 0; i < bulletCount; i++) {
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

void Enemy::ChangeMove(float _moveX, float _moveY) {
	moveX = _moveX;
	moveY = _moveY;
}

void Enemy::ChangeMove(MOVE_TYPE *moveType) {
	switch (*moveType) {
		case MOVE_TYPE::UP: {
			moveX = 0.0f;
			moveY = -1.0f;
			break;
		}
		case MOVE_TYPE::UP_LEFT: {
			if (x - 80.0f > 40.0f) {
				moveX = cosf(225.0f * (DX_PI_F / 180.0f));
			}
			else {
				moveX = cosf(315.0f * (DX_PI_F / 180.0f));
				*moveType = MOVE_TYPE::UP_RIGHT;
			}
			moveY = sinf(225.0f * (DX_PI_F / 180.0f));
			break;
		}
		case MOVE_TYPE::UP_RIGHT: {
			if (x + 80.0f < 600.0f) {
				moveX = cosf(315.0f * (DX_PI_F / 180.0f));
			}
			else {
				moveX = cosf(225.0f * (DX_PI_F / 180.0f));
				*moveType = MOVE_TYPE::UP_LEFT;
			}
			moveY = sinf(225.0f * (DX_PI_F / 180.0f));
			break;
		}
		case MOVE_TYPE::DOWN: {
			moveX = 0.0f;
			moveY = 1.0f;
			break;
		}
		case MOVE_TYPE::DOWN_LEFT: {
			if (x - 80.0f > 40.0f) {
				moveX = cosf(135.0f * (DX_PI_F / 180.0f));
			}
			else {
				moveX = cosf(45.0f * (DX_PI_F / 180.0f));
				*moveType = MOVE_TYPE::DOWN_RIGHT;
			}
			moveY = sinf(135.0f * (DX_PI_F / 180.0f));
			break;
		}
		case MOVE_TYPE::DOWN_RIGHT: {
			if (x + 80.0f < 600.0f) {
				moveX = cosf(45.0f * (DX_PI_F / 180.0f));
			}
			else {
				moveX = cosf(135.0f * (DX_PI_F / 180.0f));
				*moveType = MOVE_TYPE::DOWN_LEFT;
			}
			moveY = sinf(135.0f * (DX_PI_F / 180.0f));
			break;
		}
		case MOVE_TYPE::LEFT: {
			if (x - 80.0f > 40.0f) {
				moveX = -1.0f;
			}
			else {
				moveX = 1.0f;
				*moveType = MOVE_TYPE::RIGHT;
			}
			moveY = 0.0f;
			break;
		}
		case MOVE_TYPE::RIGHT: {
			if (x + 80.0f < 600.0f) {
				moveX = 1.0f;
			}
			else {
				moveX = -1.0f;
				*moveType = MOVE_TYPE::LEFT;
			}
			moveY = 0.0f;
			break;
		}
	}
}

Enemy::~Enemy() {
	if (bullets != nullptr) {
		for (int i = 0; i < BULLET_MAX; i++) {
			if (bullets[i] != nullptr) {
				delete bullets[i];
				bullets[i] = nullptr;
			}
		}
	}
}