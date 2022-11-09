#pragma once
#include "CharaBase.h"
#include "Enemy.h"

#define DEVIATION 2000
#define BULLET_INTERVAL 10
#define PLAYER_SIZE 40

class Player :  public CharaBase
{
private:
	int score;
	int life;
	int bulletTime;
	bool isDamage;
	bool isBlink;
	int blink;
	int blinkType;
	int blinkCnt;

public:
	Player();
	void Update() override;
	void Draw() const override;
	void Hit(Location) override;
	bool LifeCheck();
	bool IsDamage() { return isDamage; }
	int GetScore();
	void Move();
	void Shot();
};

