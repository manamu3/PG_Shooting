#pragma once
#include "Enemy.h"
class RookEnemy : public Enemy
{
private:
	bool changeMovedFlag[9];
	bool backMoveFlag;
	float backPosY;
	bool sideMoveFlag;
	int sideMoveType;
	float sidePosX;
public:
	RookEnemy(float _speed, float _radius, int _point, int _hp);
	void Update() override;
};

