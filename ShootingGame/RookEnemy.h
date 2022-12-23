#pragma once
#include "Enemy.h"
class RookEnemy : public Enemy
{
private:
	bool changeMovedFlag[9];
	bool backMoveFlag;
	float backPosY;
	bool sideMoveFlag;
	float sidePosX;

	const MOVE_TYPE moveDirections[4] = {
		MOVE_TYPE::DOWN, MOVE_TYPE::LEFT, MOVE_TYPE::RIGHT, MOVE_TYPE::UP
	};

public:
	RookEnemy(float _speed, float _radius, int _point, int _hp);
	void Update() override;
};

