#pragma once

#include "AbstractScene.h"

class Title : public AbstractScene{
private:
	int cursorY;
	bool cursorMove;

public:
	Title();
	virtual ~Title() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};