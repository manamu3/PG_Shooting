#pragma once
#include "ItemBase.h"
class PowerUpItem :  public ItemBase
{
private:
	int image;

public:
	PowerUpItem(float _x, float _y);
	void Update() override;
	void Draw() const override;
};

