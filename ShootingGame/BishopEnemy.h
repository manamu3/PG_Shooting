#pragma once
#include "Enemy.h"
class BishopEnemy : public Enemy
{
private:
	bool changeMovedFlag[9];
	bool backMoveFlag;
	float backPosY;
public:
	BishopEnemy(float _speed, float _radius, int _point, int _hp);
	void Update() override;
};

