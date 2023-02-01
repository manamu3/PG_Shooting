#pragma once

#include "AbstractScene.h"
#include "Player.h"
#include "Enemy.h"
#include "ItemBase.h"

#define ENEMY_CREATE_MAX_INTERVAL 60

class GameMain : public AbstractScene
{
private:
	Player* player;
	Enemy** enemy = nullptr;
	ItemBase** item = nullptr;
	int enemyCreateTime;

	bool pawnActive[9];

	int enemyCount;
	int itemCount;

	int enemyThreat;

	int time;

	int lineY[8];

	static const int ENEMY_MAX = 60;
	static const int ITEM_MAX = 60;
	
public:
	GameMain();
	virtual ~GameMain();
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;
	void HitCheck();
	void CreateEnemy();
	void CreateItem(Location pos);
	void DeleteEnemy(int& i);
	void DeleteItem(int& i);

	bool GetPawnX(int& x);
};

