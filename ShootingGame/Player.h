#pragma once
#include "CharaBase.h"
#include "Enemy.h"
#include "ItemBase.h"
#include <map>

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

	bool isTripleBullet;
	bool isHomingBullet;

	Enemy** enemy;
	int* enemyMax;

	std::map<ITEM_TYPE, int> itemCnt;

public:
	Player(Enemy** _enemy, int* _enemyMax);
	void Update() override;
	void Draw() const override;
	bool Hit(Location) override;
	void Move();
	void Shot();
	void AddAttackBullet(int attack) { bulletDamagePoint += attack; }
	void AddScore(int _score) { score += _score; }
	void HitItem(ITEM_TYPE item);
	bool LifeCheck() { return life <= 0; }
	bool IsDamage() { return isDamage; }
	int GetScore() { return score; }
};

