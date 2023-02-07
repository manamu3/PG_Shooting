#pragma once
#include "AbstractScene.h"
class GameOver : public AbstractScene
{
private:
	int score;

public:
	GameOver(int _score);
	virtual ~GameOver() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};

