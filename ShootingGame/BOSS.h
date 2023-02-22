#pragma once

#include "Enemy.h"
#include "Player.h"
#include <vector>

class BOSS : public Enemy
{
private:
	float x, y;

	int moveCount;
	int movePattern;

	Location destination;

	int attackType;
	bool finishAttack;
	int bulletWaitTime;
	int bulletShotCount;
	int bulletLayer;

	Player *player;

	const int BULLET_WAIT_TIME = 10;

public:
	BOSS(Player *_player);
	void Update() override;
	void Draw() const override;
	void CreateBullet(int angle);

	void Move();
};

