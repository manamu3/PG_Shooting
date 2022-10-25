#pragma once
#include "BulletsBase.h"

#define RADIUS 5

class Bullet : public BulletsBase
{
public:
	Bullet();
	Bullet(float _x, float _y, float _moveX, float _moveY, float _speed, int _damage, unsigned int _color);
	void Update() override;
	void Draw() const override;
};

