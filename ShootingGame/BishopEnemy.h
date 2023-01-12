#pragma once
#include "Enemy.h"
class BishopEnemy : public Enemy
{
public:
	BishopEnemy(float _speed, float _radius, int _point, int _hp);

	void ChangeMode() override;
};

