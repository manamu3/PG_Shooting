#pragma once
#include "Enemy.h"
class PawnEnemy : public Enemy
{
public:
	PawnEnemy(float _x, float _speed, float _radius, int _point, int _hp);
};

