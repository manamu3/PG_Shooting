#pragma once
#include "CharaBase.h"

#define DEVIATION 1000

class Player :  public CharaBase
{
private:
	int score;
	int life;

public:
	Player();
	void Update() override;
	void Draw() const override;
	void Hit() override;
	bool LifeCheck();
	int GetScore();
};

