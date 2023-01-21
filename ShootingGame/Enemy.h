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
	int bulletDamage;
	float bulletSpeed;
	bool isDamage;
	std::vector<float> bulletDirection;

	float goalPos;

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
		DOWN_RIGHT,
		KNIGHT_LEFT,
		KNIGHT_RIGHT,
	};

	std::vector<MOVE_TYPE> moveDirections;

	MOVE_TYPE currentMoveType;

	int enemyMode;

public:
	//Enemy(std::vector<MOVE_TYPE> move) : moveDirections{ move } {}
	Enemy();
	~Enemy();

	void Initialize(float _moveX, float _moveY, float _speed, float _radius, int _point, int _hp, std::vector<float> _angle, float _bulletSpeed, int _bulletDamage);
	void Update() override;
	void Draw() const override;
	bool Hit(Location) override;
	void Damage(int);
	void Disabled() { isActive = false; }
	void ChangeMove(MOVE_TYPE &moveType);
	void ChangeMove();
	void CreateBullet();
	void SetEnemyX(float _x) { x = _x; }
	virtual void ChangeMode() {};

	int GetPoint() { return point; }
	int GetEnemyMode() { return enemyMode; }
	bool HpCheck() { return hp <= 0; }
	bool IsDamage() { return isDamage; }
	bool ScreenOut() { return (moveX < 0 && x <= 40.0f) || (moveX > 0 && x >= 600.0f) || (moveY < 0 && y <= 40.0f); }
	ENEMY_TYPE GetEnemyType() { return enemyType; }
};

