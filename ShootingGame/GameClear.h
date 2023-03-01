#pragma once
#include "AbstractScene.h"

class GameClear : public AbstractScene
{
private:
	int score;

public:
	GameClear(int _score);
	virtual ~GameClear() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};

