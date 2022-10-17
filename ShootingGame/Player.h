#pragma once
#include "CharaBase.h"

#define DEVIATION 2000
#define BULLET_MAX 50
#define BULLET_INTERVAL 10
#define PLAYER_SIZE 40

class Player :  public CharaBase
{
private:
	int score;
	int life;
	int bulletTime;

public:
	Player();
	void Update() override;
	void Draw() const override;
	void Hit() override;
	bool LifeCheck();
	int GetScore();
	void Move();
	void Shot();
};

