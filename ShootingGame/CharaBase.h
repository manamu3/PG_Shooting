#pragma once
#include "SphereCollider.h"
#include "Bullet.h"

class CharaBase : public SphereCollider
{
protected:
	Bullet *bullets;
	float speed;
	int images[2];
	float x;
	float y;
	float moveX;
	float moveY;
	float speed;

public:
	void Init(float _x, float _y, float _moveX, float _moveY, float _speed, float _radius);
	virtual void Update() = 0;
	virtual void Draw() const = 0;
	virtual void Hit() = 0;
	void GetBullets(Bullet* _bullets);
};

