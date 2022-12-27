#pragma once
#include "Enemy.h"
class GoldEnemy : public Enemy
{
private:
	bool changeMovedFlag[9];
	bool backMoveFlag;
	float backPosY;
	bool sideMoveFlag;
	float sidePosX;

	const MOVE_TYPE moveDirections[6] = { 
		MOVE_TYPE::DOWN_LEFT, MOVE_TYPE::DOWN, MOVE_TYPE::DOWN_RIGHT, MOVE_TYPE::LEFT, MOVE_TYPE::RIGHT, MOVE_TYPE::UP
	};

public:
	GoldEnemy(float _speed, float _radius, int _point, int _hp);
	void Update() override;
};

