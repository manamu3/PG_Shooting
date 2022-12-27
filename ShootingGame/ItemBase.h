#pragma once

#include "SphereCollider.h"

enum class ITEM_TYPE {
	POWER_UP
};

class ItemBase : public SphereCollider
{
protected:
	ITEM_TYPE type;
	float x, y;
	float speed;
	bool isActive = false;

public:
	virtual void Update() = 0;
	virtual void Draw() const = 0;
	void Disabled() { isActive = false; }

	ITEM_TYPE GetType() { return type; }
	bool IsActive() { return isActive; }
	bool Hit(Location player);
};

