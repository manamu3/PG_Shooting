#pragma once
#include "Enemy.h"
class GoldEnemy : public Enemy
{
private:
	bool changeMovedFlag[9];
	bool backMoveFlag;
	float backPosY;
	int sideMoveFlag;
	float sidePosX;
public:
	GoldEnemy(float _speed, float _radius, int _point, int _hp);
	void Update() override;
};

