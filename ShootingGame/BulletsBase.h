#pragma once
#include "SphereCollider.h"

class BulletsBase : public SphereCollider
{
protected:
	bool isEnable = false;
	int damage;
	unsigned int color;
	float x;
	float y;
	float moveX;
	float moveY;
	float speed;

public:
	virtual void Update() = 0;
	virtual void Draw() const = 0;
	int GetDamage();
	bool IsEnable();
};

