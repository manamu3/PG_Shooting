#pragma once
#include "Bullet.h"

class CharaBase
{
private:
	Bullet *bullets;
	float speed;
	int image;

public:
	virtual void Update() = 0;
	virtual void Draw() const = 0;
	virtual void Hit() = 0;
	void GetBullets(Bullet* _bullets);
};

