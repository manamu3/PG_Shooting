#pragma once
#include "Enemy.h"
class PawnEnemy : public Enemy
{
private:
	int randX;
	static bool pawnActive[9];

public:
	PawnEnemy(float _speed, float _radius, int _point, int _hp);
	void Update() override;
};

