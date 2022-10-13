#include "GameMain.h"
#include "DxLib.h"
#include "Enemy.h"

GameMain::GameMain() {
	player.Init(320, 420, 0, 0, 5, 3);
	enemy = new Enemy[30];
	enemyCreateTime = GetRand(ENEMY_CREATE_MAX_INTERVAL);
}

AbstractScene* GameMain::Update() {
	player.Update();
	if (--enemyCreateTime <= 0) {
		for (int i = 0; i < 30; i++) {
			if (!enemy[i].IsEnable()) {
				enemy[i].Init(GetRand(640), 0, 0, 1, 3, 30);
				enemyCreateTime = GetRand(ENEMY_CREATE_MAX_INTERVAL);
				break;
			}
		}
	}
	for (int i = 0; i < 30; i++) {
		if (enemy[i].IsEnable()) {
			enemy[i].Update();
		}
	}
	return this;
}

void GameMain::Draw() const {
	/*unsigned int colors[5] = {
		0x888888, 0xFF0000, 0x00FF00, 0x0000FF, 0xFFFFFF
	};
	for (int i = 0; i < 48; i++) {
		unsigned int color = 0x888888;
		if (i % 5 == 0) color = 0xFFFFFF;
		DrawLine( 0,i * 20, 960, i * 20, color);
	}
	for (int i = 0; i < 32; i++) {
		unsigned int color = 0x888888;
		if (i % 5 == 0) color = 0xFFFFFF;
		DrawLine(i * 20, 0, i * 20, 640, color);
	}*/
	player.Draw();
	for (int i = 0; i < 30; i++) {
		if (enemy[i].IsEnable()) {
			enemy[i].Draw();
		}
	}
}


bool GameMain::HitCheck() {
	return false;
}