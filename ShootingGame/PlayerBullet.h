#pragma once
#include "BulletsBase.h"
class PlayerBullet : public BulletsBase
{
public:
	PlayerBullet();
	PlayerBullet(float _x, float _y, float _speed, int _damage, unsigned int _color);
	void Update() override;
	void Draw() const override;
};

