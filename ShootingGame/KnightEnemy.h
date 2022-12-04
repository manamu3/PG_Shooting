#pragma once
#include "Enemy.h"
class KnightEnemy : public Enemy
{
private:
	bool changeMovedFlag[9];

public:
	KnightEnemy(float _speed, float _radius, int _point, int _hp);
	void Update(bool _changeMove = false, float _moveX = 0.0f, float _moveY = 0.0f) override;
};

