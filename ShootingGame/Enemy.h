#pragma once
#include "CharaBase.h"
#include <vector>

enum class ENEMY_TYPE {
	PAWN,
	LANCE,
	KNIGHT,
	SILVER,
	GOLD,
	BISHOP,
	ROOK
};

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
	ENEMY_TYPE enemyType;

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
	Enemy();
	~Enemy();

	void Initialize(float x, float _moveX, float _moveY, float _speed, float _radius, int _point, int _hp, std::vector<float> _angle, float _bulletSpeed, int _bulletDamage);
	void Update() override;
	void Draw() const override;
	void Hit(Location) override;
	void Damage(int);
	void Disabled() { isActive = false; }
	void ChangeMove(MOVE_TYPE &moveType);
	void ChangeMove(float _moveX, float _moveY);
	void CreateBullet();

	bool HpCheck() { return hp <= 0; }
	bool IsDamage() { return isDamage; }
	int GetPoint() { return point; }
	int GetBulletNum() { return bulletCount; }
	ENEMY_TYPE GetEnemyType() { return enemyType; }
};

