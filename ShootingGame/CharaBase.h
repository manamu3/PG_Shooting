#pragma once
#include "SphereCollider.h"
#include "Bullet.h"
#include "ImageManager.h"

#define BULLET_MAX 50

class CharaBase : public SphereCollider, public ImageManager
{
protected:
	Bullet **bullets = nullptr;
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
	Bullet** GetBullets();
	bool IsActive();
};

