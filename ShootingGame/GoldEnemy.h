#pragma once
#include "Enemy.h"
class GoldEnemy : public Enemy
{
public:
	GoldEnemy(float _speed, float _radius, int _point, int _hp);

	void ChangeMode() override;
};

