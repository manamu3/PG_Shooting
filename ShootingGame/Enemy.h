#pragma once
#include "CharaBase.h"
#include <vector>

class Enemy : public CharaBase
{
private:
	int hp;
	int point;
	int bulletTime = 0;
	int bulletCount = 0;
	int bulletDamage;
	float bulletSpeed;
	bool isDamage;
	std::vector<float> bulletDirection;

	static const int ENEMY_BULLET_INTERVAL = 180;

protected:

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
	void Disabled() { isActive = false; }
	void ChangeMove(MOVE_TYPE *moveType);
	void ChangeMove(float _moveX, float _moveY);
	bool HpCheck() { return hp <= 0; }
	bool IsDamage() { return isDamage; }
	int GetPoint() { return point; }
	~Enemy();
};

