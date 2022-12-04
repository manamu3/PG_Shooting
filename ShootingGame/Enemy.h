#pragma once
#include "CharaBase.h"
#include <vector>

#define ENEMY_BULLET_INTERVAL 180

class Enemy : public CharaBase
{
protected:
	int hp;
	int point;
	int bulletTime = 0;
	float bulletSpeed;
	int bulletDamage;
	bool isDamage;
	std::vector<float> bulletDirection;

public:
	void Initialize(float x, float _moveX, float _moveY, float _speed, float _radius, int _point, int _hp, std::vector<float> _angle, float _bulletSpeed, int _bulletDamage);
	void Update() override;
	void Draw() const override;
	void Hit(Location) override;
	void Damage(int);
	bool HpCheck();
	bool IsDamage();
	int GetPoint();
	void Disabled() { isActive = false; }
	void ChangeMove(float _moveX, float _moveY);
	~Enemy();
};

