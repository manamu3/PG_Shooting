#pragma once

#include "AbstractScene.h"

class Title : public AbstractScene{
public:
	virtual ~Title() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
};