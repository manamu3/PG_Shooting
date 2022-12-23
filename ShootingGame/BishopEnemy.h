#pragma once
#include "Enemy.h"
class BishopEnemy : public Enemy
{
private:
	bool changeMovedFlag[9];
	bool backMoveFlag;
	float backPosY;

	const MOVE_TYPE moveDirections[4] = { 
		MOVE_TYPE::DOWN_LEFT, MOVE_TYPE::DOWN_RIGHT, MOVE_TYPE::UP_LEFT, MOVE_TYPE::UP_RIGHT
	};

public:
	BishopEnemy(float _speed, float _radius, int _point, int _hp);
	void Update() override;
};

