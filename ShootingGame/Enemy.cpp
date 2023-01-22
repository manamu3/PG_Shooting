#include "Enemy.h"
#include "DxLib.h"
#include "EnemyBullet.h"

Enemy::Enemy() {
	bullets = (new BulletsBase * [BULLET_MAX]);
	for (int i = 0; i < BULLET_MAX; i++) {
		bullets[i] = nullptr;
	}
	isDamage = false;
	bulletTime = GetRand(ENEMY_BULLET_INTERVAL);
	enemyMode = 0;
}

void Enemy::Initialize(float _moveX, float _moveY, float _speed, float _radius, int _point, int _hp, std::vector<float> _bulletAngle, float _bulletSpeed, int _bulletDamage) {
	hp = _hp;
	point = _point;
	bulletDirection = _bulletAngle;
	bulletSpeed = _bulletSpeed;
	bulletDamage = _bulletDamage;
	ImageManager::GetEnemyImage(static_cast<int>(enemyType), images);

	float randX = (640.0f / 9.0f) * GetRand(8) + 35.0f;
	CharaBase::Init(randX, 0, _moveX, _moveY, _speed, _radius);

	goalPos = y + 80.0f;
}

void Enemy::Update() {
	if (isActive) {
		x += moveX * speed;
		y += moveY * speed;
		Location nowLocation = { x, y };
		SetLocation(nowLocation);
		ChangeMove();
		if (y > 480) {
			isActive = false;
		}
		if (y > 360) {
			ChangeMode();
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
				DeleteBullet(i);
			}
		}
	}
}

void Enemy::CreateBullet() {
	int count = 0;
	for (int i = bulletCount; i < BULLET_MAX; i++) {
		if (bullets[i] == nullptr) {
			bullets[i] = new EnemyBullet(x, y, bulletDirection[count], bulletSpeed, bulletDamage, 0x000000);
			bulletCount++;
			if (++count >= bulletDirection.size()) {
				break;
			}
		}
	}
}

void Enemy::Draw() const {
	if (isActive) {
		DrawRotaGraphF(x, y, 1.0, 0.0, images[enemyMode], TRUE);
	}
	for (int i = 0; i < bulletCount; i++) {
		if (bullets[i] != nullptr) {
			bullets[i]->Draw();
		}
	}
}

bool Enemy::Hit(Location pos) {
	if (HitSphere(pos)) {
		isDamage = true;
		return true;
	}

	return false;
}

void Enemy::Damage(int damage) {
	hp -= damage;
	if (HpCheck()) {
		isActive = false;
	}
	isDamage = false;
}

void Enemy::ChangeMove() {
	MOVE_TYPE moveDirection = moveDirections[GetRand(moveDirections.size() - 1)];
	if (ScreenOut()) {
		ChangeMove(moveDirection);
		return;
	}
	if (currentMoveType == MOVE_TYPE::UP || currentMoveType == MOVE_TYPE::UP_LEFT || currentMoveType == MOVE_TYPE::UP_RIGHT) {
		if (goalPos > y) {
			ChangeMove(moveDirection);
		}
	}
	else if (currentMoveType == MOVE_TYPE::LEFT || currentMoveType == MOVE_TYPE::RIGHT) {
		if (fabsf(goalPos - x) < speed) {
			ChangeMove(moveDirection);
		}
	}
	else {
		if (goalPos < y) {
			ChangeMove(moveDirection);
		}
	}
}

void Enemy::ChangeMove(MOVE_TYPE &moveType) {
	switch (moveType) {
		case MOVE_TYPE::UP: {
			moveX = 0.0f;
			moveY = -1.0f;
			goalPos = y - 80.0f;
			break;
		}
		case MOVE_TYPE::UP_LEFT: {
			if (x - 80.0f > 40.0f) {
				moveX = cosf(225.0f * (DX_PI_F / 180.0f));
			}
			else {
				moveX = cosf(315.0f * (DX_PI_F / 180.0f));
				moveType = MOVE_TYPE::UP_RIGHT;
			}
			moveY = sinf(225.0f * (DX_PI_F / 180.0f));
			goalPos = y - 80.0f;
			break;
		}
		case MOVE_TYPE::UP_RIGHT: {
			if (x + 80.0f < 600.0f) {
				moveX = cosf(315.0f * (DX_PI_F / 180.0f));
			}
			else {
				moveX = cosf(225.0f * (DX_PI_F / 180.0f));
				moveType = MOVE_TYPE::UP_LEFT;
			}
			moveY = sinf(225.0f * (DX_PI_F / 180.0f));
			goalPos = y - 80.0f;
			break;
		}
		case MOVE_TYPE::DOWN: {
			moveX = 0.0f;
			moveY = 1.0f;
			goalPos = y + 80.0f;
			break;
		}
		case MOVE_TYPE::DOWN_LEFT: {
			if (x - 80.0f > 40.0f) {
				moveX = cosf(135.0f * (DX_PI_F / 180.0f));
			}
			else {
				moveX = cosf(45.0f * (DX_PI_F / 180.0f));
				moveType = MOVE_TYPE::DOWN_RIGHT;
			}
			moveY = sinf(135.0f * (DX_PI_F / 180.0f));
			goalPos = y + 80.0f;
			break;
		}
		case MOVE_TYPE::DOWN_RIGHT: {
			if (x + 80.0f < 600.0f) {
				moveX = cosf(45.0f * (DX_PI_F / 180.0f));
			}
			else {
				moveX = cosf(135.0f * (DX_PI_F / 180.0f));
				moveType = MOVE_TYPE::DOWN_LEFT;
			}
			moveY = sinf(135.0f * (DX_PI_F / 180.0f));
			goalPos = y + 80.0f;
			break;
		}
		case MOVE_TYPE::LEFT: {
			if (x - 80.0f > 40.0f) {
				moveX = -1.0f;
			}
			else {
				moveX = 1.0f;
				moveType = MOVE_TYPE::RIGHT;
			}
			moveY = 0.0f;
			goalPos = x - 80.0f;
			break;
		}
		case MOVE_TYPE::RIGHT: {
			if (x + 80.0f < 600.0f) {
				moveX = 1.0f;
			}
			else {
				moveX = -1.0f;
				moveType = MOVE_TYPE::LEFT;
			}
			moveY = 0.0f;
			goalPos = x + 80.0f;
			break;
		}
		case MOVE_TYPE::KNIGHT_LEFT: {
			if (x - 80.0f > 40.0f) {
				moveX = cosf(120.0f * (DX_PI_F / 180.0f));
			}
			else {
				moveX = cosf(60.0f * (DX_PI_F / 180.0f));
				moveType = MOVE_TYPE::KNIGHT_RIGHT;
			}
			moveY = sinf(135.0f * (DX_PI_F / 180.0f));
			goalPos = y + 160.0f;
			break;
		}
		case MOVE_TYPE::KNIGHT_RIGHT: {
			if (x + 40.0f < 600.0f) {
				moveX = cosf(60.0f * (DX_PI_F / 180.0f));
			}
			else {
				moveX = cosf(120.0f * (DX_PI_F / 180.0f));
				moveType = MOVE_TYPE::KNIGHT_LEFT;
			}
			moveY = sinf(135.0f * (DX_PI_F / 180.0f));
			goalPos = y + 160.0f;
			break;
		}
	}

	currentMoveType = moveType;
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