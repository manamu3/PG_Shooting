#pragma once
#include "CharaBase.h"

#define ENEMY_BULLET_INTERVAL 300

class Enemy : public CharaBase
{
private:
	int hp;
	int point;
	int bulletTime = 0;

public:
	Enemy();
	void Update() override;
	void Draw() const override;
	void Hit() override;
	bool HpCheck();
	int GetPoint();
};

