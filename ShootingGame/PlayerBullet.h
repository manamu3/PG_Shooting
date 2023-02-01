#pragma once
#include "BulletsBase.h"
#include "Enemy.h"
class PlayerBullet : public BulletsBase
{
private:
	Enemy* targetEnemy = nullptr;

	bool isHoming;

public:
	PlayerBullet(float _x, float _y, float _speed, int _damage, unsigned int _color, Enemy** _enemy, int _enemyMax, bool _isHoming = false);
	PlayerBullet(float _x, float _y, float _mx, float _my, float _speed, int _damage, unsigned int _color);
	void Update() override;
	void Draw() const override;
};

