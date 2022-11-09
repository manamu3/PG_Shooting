#pragma once
#include "SphereCollider.h"

#define RADIUS 5

class BulletsBase : public SphereCollider
{
protected:
	bool isActive = false;
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
	void Disabled() { isActive = false; }
	int GetDamage() { return damage; }
	bool IsActive() { return isActive; }
};

