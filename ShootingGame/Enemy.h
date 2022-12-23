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

	enum class MOVE_TYPE {
		UP,
		DOWN,
		LEFT,
		RIGHT,
		UP_LEFT,
		UP_RIGHT,
		DOWN_LEFT,
		DOWN_RIGHT
	};

	//const std::vector<MOVE_TYPE> moveDirections;

public:
	//Enemy(std::vector<MOVE_TYPE> move) : moveDirections{ move } {}
	void Initialize(float x, float _moveX, float _moveY, float _speed, float _radius, int _point, int _hp, std::vector<float> _angle, float _bulletSpeed, int _bulletDamage);
	void Update() override;
	void Draw() const override;
	void Hit(Location) override;
	void Damage(int);
	bool HpCheck();
	bool IsDamage();
	int GetPoint();
	void Disabled() { isActive = false; }
	void ChangeMove(MOVE_TYPE *moveType);
	void ChangeMove(float _moveX, float _moveY);
	~Enemy();
};

