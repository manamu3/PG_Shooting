#pragma once

#include "AbstractScene.h"
class GameMain : public AbstractScene
{
	GameMain();
	virtual ~GameMain() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};

