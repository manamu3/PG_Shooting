#pragma once
#include "Enemy.h"
class PawnEnemy : public Enemy
{
private:
	int randX;
	static bool pawnActive[9];

public:
	PawnEnemy();
	PawnEnemy(float _moveX, float _moveY, float _speed, float _radius, int _point, int _hp);
	void Update() override;
	void Draw() const override;
};

