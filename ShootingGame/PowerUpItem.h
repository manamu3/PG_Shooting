#pragma once
#include "ItemBase.h"
class PowerUpItem :  public ItemBase
{
public:
	PowerUpItem(float _x, float _y);
	void Update() override;
	void Draw() const override;
};

