#include "Enemy.h"
#include "DxLib.h"

void Enemy::Update() {
	y += moveY * speed;
	if (y > 500) isEnable = false;
}

void Enemy::Draw() const {
	DrawCircle(x, y, 10, 0xFF0000, TRUE);
	
}

void Enemy::Hit() {

}

bool Enemy::HpCheck() {
	return hp <= 0;
}

int Enemy::GetPoint() {
	return point;
}