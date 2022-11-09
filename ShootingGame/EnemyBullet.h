#pragma once
#include "BulletsBase.h"

class EnemyBullet : public BulletsBase
{
public:
	EnemyBullet();
	EnemyBullet(float _x, float _y, int _bulletAngle, float _speed, int _damage, unsigned int _color);
	void Update() override;
	void Draw() const override;
};

