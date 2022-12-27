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
	int bulletDamagePoint;

public:
	Player();
	void Update() override;
	void Draw() const override;
	bool Hit(Location) override;
	void Move();
	void Shot();
	void AddAttackBullet(int attack) { bulletDamagePoint += attack; }
	bool LifeCheck() { return life <= 0; }
	bool IsDamage() { return isDamage; }
	int GetScore() { return score; }
};

