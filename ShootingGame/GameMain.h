#pragma once

#include "AbstractScene.h"
#include "Player.h"
#include "Enemy.h"

#define ENEMY_CREATE_MAX_INTERVAL 60

class GameMain : public AbstractScene
{
private:
	Player player;
	Enemy* enemy = nullptr;
	int enemyCreateTime;
	
public:
	GameMain();
	virtual ~GameMain() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
	void HitCheck();
};

