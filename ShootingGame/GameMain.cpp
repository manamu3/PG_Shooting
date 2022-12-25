#include "GameMain.h"
#include "DxLib.h"

#include "PawnEnemy.h"
#include "LanceEnemy.h"
#include "KnightEnemy.h"
#include "SilverEnemy.h"
#include "GoldEnemy.h"
#include "BishopEnemy.h"
#include "RookEnemy.h"

#include "BulletsBase.h"
#include "PowerUpItem.h"

GameMain::GameMain() {
	player.Init(320, 420, 0, 0, 5, 30);

	enemy = new Enemy *[ENEMY_MAX];
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemy[i] = nullptr;
	}

	item = new ItemBase *[ITEM_MAX];
	for (int i = 0; i < ITEM_MAX; i++) {
		item[i] = nullptr;
	}
	enemyCreateTime = GetRand(ENEMY_CREATE_MAX_INTERVAL);
}

AbstractScene* GameMain::Update() {
	player.Update();

	if (--enemyCreateTime <= 0) {
		CreateEnemy();
		enemyCreateTime = GetRand(ENEMY_CREATE_MAX_INTERVAL);
	}

	for (int i = 0; i < ENEMY_MAX; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Update();
			if (!enemy[i]->IsActive()) {
				delete enemy[i];
				enemy[i] = nullptr;
			}
		}
	}

	for (int i = 0; i < ITEM_MAX; i++) {
		if (item[i] != nullptr) {
			item[i]->Update();
			if (!item[i]->IsActive()) {
				delete item[i];
				item[i] = nullptr;
			}
		}
	}

	HitCheck();

	return this;
}

void GameMain::Draw() const {
	player.Draw();

	for (int i = 0; i < ENEMY_MAX; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Draw();
		}
	}

	for (int i = 0; i < ITEM_MAX; i++) {
		if (item[i] != nullptr) {
			item[i]->Draw();
		}
	}
}

void GameMain::CreateEnemy() {
	int enemyType = GetRand(999);
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (enemy[i] == nullptr) {
			if (enemyType < 650) {
				enemy[i] = new PawnEnemy(3, 15, 100, 3);
			}
			else if (enemyType < 750) {
				enemy[i] = new LanceEnemy(6, 15, 100, 3);
			}
			else if (enemyType < 850) {
				enemy[i] = new KnightEnemy(4.5f, 15, 100, 3);
			}
			else if (enemyType < 900) {
				enemy[i] = new SilverEnemy(3.0f, 15, 100, 3);
			}
			else if (enemyType < 950) {
				enemy[i] = new GoldEnemy(3.0f, 15, 100, 3);
			}
			else if (enemyType < 975) {
				enemy[i] = new BishopEnemy(6, 15, 100, 3);
			}
			else {
				enemy[i] = new RookEnemy(6, 15, 100, 3);
			}
			return;
		}
	}
}

void GameMain::CreateItem(Location pos) {
	for (int i = 0; i < ITEM_MAX; i++) {
		if (item[i] == nullptr) {
			item[i] = new PowerUpItem(pos.x, pos.y);
			return;
		}
	}
}

void GameMain::HitCheck() {
	BulletsBase** playerBullets = (player.GetBullets());
	//敵の当たり判定
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (enemy[i] == nullptr) continue;
		//プレイヤーと当たった時の処理
		player.Hit(enemy[i]->GetLocation());
		for (int j = 0; j < BULLET_MAX; j++) {
			if (playerBullets[j] == nullptr) continue;
			//プレイヤーの弾との当たり判定
			enemy[i]->Hit(playerBullets[j]->GetLocation());
			if (enemy[i]->IsDamage()) {
				enemy[i]->Damage(playerBullets[j]->GetDamage());
				enemy[i]->Disabled();

				CreateItem(enemy[i]->GetLocation());
				
				playerBullets[j]->Disabled();
				break;
			}
		}
	}
	for (int i = 0; i < ENEMY_MAX; i++) {
		if (enemy[i] == nullptr) continue;

		player.Hit(enemy[i]->GetLocation());
		BulletsBase** enemyBullets = enemy[i]->GetBullets();
		for (int j = 0; j < BULLET_MAX; j++) {
			if (enemyBullets[j] == nullptr) continue;
			player.Hit(enemyBullets[j]->GetLocation());
			if (player.IsDamage()) {
				enemyBullets[j]->Disabled();
				break;
			}
		}
	}
	for (int i = 0; i < ITEM_MAX; i++) {
		if (item[i] == nullptr) continue;

		if (item[i]->Hit(player.GetLocation())) {
			switch (item[i]->GetType()) {
			case ITEM_TYPE::POWER_UP:
				player.AddAttackBullet(1);
				break;
			}
		}
	}
}