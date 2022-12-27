#pragma once
#include "Enemy.h"
class KnightEnemy : public Enemy
{
private:
	bool changeMovedFlag[5];

public:
	KnightEnemy(float _speed, float _radius, int _point, int _hp);
	void Update() override;
	void GetNextMove(float& moveX);
};

