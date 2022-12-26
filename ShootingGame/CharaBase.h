#pragma once
#include "SphereCollider.h"
#include "BulletsBase.h"
#include "ImageManager.h"

#define BULLET_MAX 100

class CharaBase : public SphereCollider
{
protected:
	BulletsBase **bullets = nullptr;
	bool isActive = false;
	int images[2];
	float speed;
	float x;
	float y;
	float moveX;
	float moveY;

public:
	void Init(float _x, float _y, float _moveX, float _moveY, float _speed, float _radius);
	virtual void Update() = 0;
	virtual void Draw() const = 0;
	virtual void Hit(Location) = 0;
	BulletsBase **GetBullets();
	bool IsActive();
};

