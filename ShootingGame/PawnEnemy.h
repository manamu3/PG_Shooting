#pragma once
#include "Enemy.h"
class PawnEnemy : public Enemy
{
private:
	int randX;
	static bool pawnActive[9];

public:
	PawnEnemy(float _speed, float _radius, int _point, int _hp);
	void Update(bool _changeMove = false, float _moveX = 0.0f, float _moveY = 0.0f) override;
};

