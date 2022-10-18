#pragma once
#include "CharaBase.h"

#define ENEMY_BULLET_INTERVAL 300

class Enemy : public CharaBase
{
private:
	int hp;
	int point;
	int bulletTime = 0;
	bool isDamage;

public:
	Enemy();
	void Init(float _x, float _y, float _moveX, float _moveY, float _speed, float _radius, int _hp);
	void Update() override;
	void Draw() const override;
	void Hit(Location) override;
	void Damage(int);
	bool HpCheck();
	bool IsDamage();
	int GetPoint();
};

