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
	for (int i = 0; i < 9; i++) {
		pawnActive[i] = false;
	}

	item = new ItemBase *[ITEM_MAX];
	for (int i = 0; i < ITEM_MAX; i++) {
		item[i] = nullptr;
	}

	enemyCreateTime = GetRand(ENEMY_CREATE_MAX_INTERVAL);

	enemyCount = 0;
	itemCount = 0;

	enemyThreat = 0;
}

AbstractScene* GameMain::Update() {
	player.Update();

	if (--enemyCreateTime <= 0) {
		CreateEnemy();
		enemyCreateTime = GetRand(ENEMY_CREATE_MAX_INTERVAL);
	}

	for (int i = 0; i < enemyCount; i++) {
		if (enemy[i] != nullptr) {
			bool changeMode = enemy[i]->GetEnemyMode() == 0;
			enemy[i]->Update();
			if (enemy[i]->GetEnemyType() == ENEMY_TYPE::PAWN && enemy[i]->GetEnemyMode() == 1 && changeMode) {
				int x = (enemy[i]->GetLocation().x - 20.0f) / (640.0f / 9.0f);
				pawnActive[x] = false;
			}
			if (!enemy[i]->IsActive() && enemy[i]->GetBulletNum() <= 0) {
				DeleteEnemy(i);
			}
		}
	}

	for (int i = 0; i < itemCount; i++) {
		if (item[i] != nullptr) {
			item[i]->Update();
			if (!item[i]->IsActive()) {
				DeleteItem(i);
			}
		}
	}

	HitCheck();

	return this;
}

void GameMain::Draw() const {
	player.Draw();
	for (int i = 0; i < enemyCount; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Draw();
		}
	}

	for (int i = 0; i < itemCount; i++) {
		if (item[i] != nullptr) {
			item[i]->Draw();
		}
	}
}

void GameMain::CreateEnemy() {
	int enemyType = GetRand(999);
	if (enemyThreat > 15) return;
	for (int i = enemyCount; i < ENEMY_MAX; i++) {
		if (enemy[i] == nullptr) {
			if (enemyType < 650) {
				int x = GetRand(8);
				if (GetPawnX(x)) {
					enemy[i] = new PawnEnemy((640.0f / 9.0f) * (float)x + 20.0f, 2, 15, 100, 3);
					pawnActive[x] = true;
					enemyCount++;
					enemyThreat += 1;
					return;
				}
				else {
					enemyType = GetRand(349) + 650;
				}
			}
			if (enemyType < 750) {
				enemy[i] = new LanceEnemy(4, 15, 300, 6);
				enemyThreat += 2;
			}
			else if (enemyType < 850) {
				enemy[i] = new KnightEnemy(3, 15, 500, 10);
				enemyThreat += 3;
			}
			else if (enemyType < 900) {
				enemy[i] = new SilverEnemy(2, 15, 800, 15);
				enemyThreat += 4;
			}
			else if (enemyType < 950) {
				enemy[i] = new GoldEnemy(2, 15, 1000, 15);
				enemyThreat += 4;
			}
			else if (enemyType < 975) {
				enemy[i] = new BishopEnemy(4, 15, 1200, 20);
				enemyThreat += 5;
			}
			else {
				enemy[i] = new RookEnemy(4, 15, 1200, 20);
				enemyThreat += 5;
			}
			enemyCount++;
			return;
		}
	}
}

bool GameMain::GetPawnX(int& x) {
	if (pawnActive[x]) {
		int i;
		for (i = 0; i < 9; i++) {
			if (!pawnActive[i]) {
				break;
			}
		}
		if (i < 9) {
			while (pawnActive[x]) {
				x = GetRand(8);
			}
			return true;
		}
		else {
			return false;
		}
	}

	return true;
}

void GameMain::CreateItem(Location pos) {
	for (int i = itemCount; i < ITEM_MAX; i++) {
		if (item[i] == nullptr) {
			item[i] = new PowerUpItem(pos.x, pos.y);
			itemCount++;
			return;
		}
	}
}

void GameMain::DeleteEnemy(int &i) {
	if (enemy[i]->GetEnemyType() == ENEMY_TYPE::PAWN) {
		int x = (enemy[i]->GetLocation().x - 20.0f) / (640.0f / 9.0f);
		pawnActive[x] = false;
	}
	switch (enemy[i]->GetEnemyType()) {
	case ENEMY_TYPE::PAWN:
		enemyThreat -= 1;
		break;
	case ENEMY_TYPE::LANCE:
		enemyThreat -= 2;
		break;
	case ENEMY_TYPE::KNIGHT:
		enemyThreat -= 3;
		break;
	case ENEMY_TYPE::SILVER:
		enemyThreat -= 4;
		break;
	case ENEMY_TYPE::GOLD:
		enemyThreat -= 4;
		break;
	case ENEMY_TYPE::BISHOP:
		enemyThreat -= 5;
		break;
	case ENEMY_TYPE::ROOK:
		enemyThreat -= 5;
		break;
	}
	enemyCount--;
	Enemy *temp = enemy[i];
	enemy[i] = enemy[enemyCount];
	enemy[enemyCount] = temp;
	delete enemy[enemyCount];
	enemy[enemyCount] = nullptr;
	(i)--;
}

void GameMain::DeleteItem(int &i) {
	itemCount--;
	*item[i] = *item[itemCount];
	delete item[itemCount];
	item[itemCount] = nullptr;
	(i)--;
}

void GameMain::HitCheck() {
	BulletsBase** playerBullets = (player.GetBullets());
	//敵の当たり判定
	for (int i = 0; i < enemyCount; i++) {
		if (enemy[i] == nullptr || !enemy[i]->IsActive()) continue;

		//プレイヤーと当たった時の処理
		player.Hit(enemy[i]->GetLocation());

		//プレイヤーの弾の当たり判定
		for (int j = 0; j < player.GetBulletNum(); j++) {
			if (playerBullets[j] == nullptr) continue;

			//プレイヤーの弾と当たった時の処理
			if (enemy[i]->Hit(playerBullets[j]->GetLocation())) {
				//ダメージ
				enemy[i]->Damage(playerBullets[j]->GetDamage());
				//死亡判定
				if (enemy[i]->HpCheck()) {
					//アイテム生成
					CreateItem(enemy[i]->GetLocation());
					//スコア加算
					player.AddScore(enemy[i]->GetPoint());
					//敵の削除
					enemy[i]->Disabled();
					//DeleteEnemy(i);
				}
				//自弾の削除
				player.DeleteBullet(j);
				break;
			}
		}

		if (i < 0) continue;

		//敵と当たったら
		player.Hit(enemy[i]->GetLocation());
		BulletsBase** enemyBullets = enemy[i]->GetBullets();

		//敵弾の当たり判定
		for (int j = 0; j < enemy[i]->GetBulletNum(); j++) {
			if (enemyBullets[j] == nullptr) continue;

			//プレイヤーと当たったら
			if (player.Hit(enemyBullets[j]->GetLocation())) {
				enemy[i]->DeleteBullet(j);
				break;
			}
		}
	}
	for (int i = 0; i < itemCount; i++) {
		if (item[i] == nullptr) continue;

		if (item[i]->Hit(player.GetLocation())) {
			player.HitItem(item[i]->GetType());
			DeleteItem(i);
		}
	}
}