#include "GameMain.h"
#include "DxLib.h"
#include "Enemy.h"

GameMain::GameMain() {
	player.Init(320, 420, 0, 0, 5, 30);
	enemy = new Enemy[30];
	enemyCreateTime = GetRand(ENEMY_CREATE_MAX_INTERVAL);
}

AbstractScene* GameMain::Update() {
	player.Update();
	if (--enemyCreateTime <= 0) {
		for (int i = 0; i < 30; i++) {
			if (!enemy[i].IsEnable()) {
				enemy[i].Init(0, 1, 3, 15, 3);
				enemyCreateTime = GetRand(ENEMY_CREATE_MAX_INTERVAL);
				break;
			}
		}
	}
	for (int i = 0; i < 30; i++) {
		enemy[i].Update();
	}

	HitCheck();

	return this;
}

void GameMain::Draw() const {
	player.Draw();

	for (int i = 0; i < 30; i++) {
		enemy[i].Draw();
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
	Bullet** playerBullets = (player.GetBullets());
	for (int i = 0; i < 30; i++) {
		if (!enemy[i].IsEnable()) continue;

		player.Hit(enemy[i].GetLocation());
		for (int j = 0; j < BULLET_MAX; j++) {
			if (playerBullets[j] == nullptr) continue;

			enemy[i].Hit(playerBullets[j]->GetLocation());
			if (enemy[i].IsDamage()) {
				enemy[i].Damage(playerBullets[j]->GetDamage());
				playerBullets[j]->Disabled();
				break;
			}
		}
	}
	for (int i = 0; i < 30; i++) {
		if (!enemy[i].IsEnable()) continue;

		player.Hit(enemy[i].GetLocation());
		Bullet** enemyBullets = enemy[i].GetBullets();
		for (int j = 0; j < BULLET_MAX; j++) {
			if (enemyBullets[j] == nullptr) continue;

			player.Hit(enemyBullets[j]->GetLocation());
			break;
		}
	}
}