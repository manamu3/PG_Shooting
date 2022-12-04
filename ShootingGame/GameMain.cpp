#include "GameMain.h"
#include "DxLib.h"
#include "Enemy.h"
#include "PawnEnemy.h"
#include "LanceEnemy.h"
#include "KnightEnemy.h"
#include "SilverEnemy.h"
#include "BulletsBase.h"
#include "PowerUpItem.h"

GameMain::GameMain() {
	player.Init(320, 420, 0, 0, 5, 30);
	enemy = new Enemy *[30];
	item = new ItemBase *[30];
	for (int i = 0; i < 30; i++) {
		enemy[i] = nullptr;
		item[i] = nullptr;
	}
	enemyCreateTime = GetRand(ENEMY_CREATE_MAX_INTERVAL);
}

AbstractScene* GameMain::Update() {
	player.Update();
	if (--enemyCreateTime <= 0) {
		for (int i = 0; i < 30; i++) {
			if (enemy[i] == nullptr) {
				int enemyType = GetRand(99);
				if (enemyType < 65) {
					enemy[i] = new PawnEnemy(3, 15, 100, 3);
				}
				else if (enemyType < 85) {
					if (enemyType - 65 < 10) {
						enemy[i] = new LanceEnemy(6, 15, 100, 3);
					}
					else {
						enemy[i] = new KnightEnemy(4.5f, 15, 100, 3);
					}
				}
				else if (enemyType < 95) {
					if (enemyType - 85 < 10) {
						enemy[i] = new SilverEnemy(3.0f, 15, 100, 3);
					}
					else {
						enemy[i] = new SilverEnemy(4.5f, 15, 100, 3);
					}
				}
				else {
					/*if (GetRand(49) < 25) {

					}
					else {

					}*/
					enemy[i] = new PawnEnemy(3, 15, 100, 3);
				}
				//clsDx();
				//printfDx("enemyType: %d\n", enemyType);
				enemyCreateTime = GetRand(ENEMY_CREATE_MAX_INTERVAL);
				break;
			}
		}
	}
	for (int i = 0; i < 30; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Update();
			if (!enemy[i]->IsActive()) {
				delete enemy[i];
				enemy[i] = nullptr;
			}
		}
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

	for (int i = 0; i < 30; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Draw();
		}
		if (item[i] != nullptr) {
			item[i]->Draw();
		}
	}

	/*for (int i = 0; i < 48; i++) {
		if ((i + i) % 5 == 0)
			DrawLine(i * 20, 0, i * 20, 640, 0xFFFFFF);
		else 
			DrawLine(i * 20, 0, i * 20, 640, 0x888888);
		if ((i + i) % 5 == 0)
			DrawLine(0, i * 20, 960,i * 20,  0xFFFFFF);
		else
			DrawLine(0, i * 20, 960, i * 20, 0x888888);
	}*/
}


void GameMain::HitCheck() {
	BulletsBase** playerBullets = (player.GetBullets());
	//敵の当たり判定
	for (int i = 0; i < 30; i++) {
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

				for (int k = 0; k < 30; k++) {
					if (item[k] == nullptr) {
						Location pos = enemy[i]->GetLocation();
						item[k] = new PowerUpItem(pos.x, pos.y);
						break;
					}
				}
				if (playerBullets[j] != nullptr) {
					playerBullets[j]->Disabled();
				}
				break;
			}
		}
	}
	for (int i = 0; i < 30; i++) {
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
	for (int i = 0; i < 30; i++) {
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