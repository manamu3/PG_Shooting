#pragma once
#include "CharaBase.h"

#define ENEMY_BULLET_INTERVAL 300

class Enemy : public CharaBase
{
protected:
	int hp;
	int point;
	int bulletTime = 0;
	bool isDamage;

public:
	void Initialize(float x, float _moveX, float _moveY, float _speed, float _radius, int _point, int _hp);
	void Update() override;
	void Draw() const override;
	void Hit(Location) override;
	void Damage(int);
	bool HpCheck();
	bool IsDamage();
	int GetPoint();
	void Disabled() { isActive = false; }
	~Enemy();
};

