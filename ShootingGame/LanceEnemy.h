#pragma once

#include "Enemy.h"

class LanceEnemy : public Enemy
{
private:

public:
	LanceEnemy(float _speed, float _radius, int _point, int _hp);
	void Update() override;
};

