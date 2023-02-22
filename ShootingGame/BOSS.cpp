#include "BOSS.h"
#include "DxLib.h"
#include "EnemyBullet.h"

BOSS::BOSS(Player* _player) {
	player = _player;
	enemyType = ENEMY_TYPE::KING;
	std::vector<float> bulletAngle;

	Initialize(0.0f, 1.0f, 4.0f, 30, 5000, 5000, bulletAngle, 6.0f, 3);
	x = 320;

	moveCount = 0;
	movePattern = 0;
	attackType = 3;
	bulletShotCount = 0;
	bulletWaitTime = 0;
	finishAttack = true;
	destination = { 0.0f, 240.0f };
	bulletLayer = 0;
}

void BOSS::Update() {
	if (isActive) {
		if (finishAttack && attackType != 3) {
			Move();
		}
		else {
			if (finishAttack) {
				Move();
			}
			if (--bulletWaitTime <= 0) {
				//くるくる
				if (attackType == 0) {
					CreateBullet(bulletShotCount * 10);
					CreateBullet(bulletShotCount * 10 + 180);
					bulletWaitTime = BULLET_WAIT_TIME / 2;
					if (bulletShotCount >= 36) {
						finishAttack = true;
					}
				}
				//回転
				else if (attackType == 1) {
					for (int i = 0; i < 12; i++) {
						CreateBullet(i * 30 + bulletLayer * 5);
					}
					bulletLayer++;
					bulletWaitTime = BULLET_WAIT_TIME;
					if (bulletLayer >= 5) {
						finishAttack = true;
					}
				}
				//円状
				else if (attackType == 2) {
					for (int i = 0; i < 18; i++) {
						CreateBullet(i * 20);
					}
					bulletLayer++;
					bulletWaitTime = BULLET_WAIT_TIME;
					if (bulletLayer >= 5) {
						finishAttack = true;
					}
				}
				////卵
				//else if (attackType == 4) {

				//}
				//ロケット
				else if (attackType == 3) {
					for (int i = 0; i < 36; i++) {
						float rad = atan2f(destination.y - y, destination.x - x);
						int degree = (180.0f / DX_PI_F) + GetRand(20) - 190;
						CreateBullet(degree);
					}
					bulletLayer++;
					bulletWaitTime = BULLET_WAIT_TIME;
					if (bulletLayer >= 5) {
						finishAttack = true;
					}
				}

				//次の目的地の設定
				if (finishAttack) {
					if (--moveCount < 0) {
						moveCount = 4;
						movePattern = (movePattern + 1) % 3;
					}
					Location nextLocation;
					if (movePattern == 0) {
						nextLocation.x = GetRand(580) + 30;
						nextLocation.y = GetRand(420) + 30;
						attackType = GetRand(3);
					}
					else if (movePattern == 1) {
						nextLocation = destination;
						attackType = GetRand(2);
					}
					else {
						nextLocation = player->GetLocation();
						attackType = 3;
					}
					if (destination.x != nextLocation.x || destination.y != nextLocation.y) {
						destination.x = nextLocation.x;
						destination.y = nextLocation.y;
						float rad = atan2f(nextLocation.y - y, nextLocation.x - x);
						moveX = cosf(rad);
						moveY = sinf(rad);
					}
					bulletShotCount = 0;
					bulletLayer = 0;
				}
			}
		}
	}
	for (int i = 0; i < bulletCount; i++) {
		if (bullets[i] != nullptr) {
			bullets[i]->Update();
			if (!bullets[i]->IsActive()) {
				DeleteBullet(i);
			}
		}
	}
}

void BOSS::Move() {
	if (destination.x > x) {
		x += moveX * speed;
		if (destination.x <= x) {
			moveX = 0;
		}
	}
	else {
		x += moveX * speed;
		if (destination.x >= x) {
			moveX = 0;
		}
	}

	if (destination.y > y) {
		y += moveY * speed;
		if (destination.y <= y) {
			moveY = 0;
		}
	}
	else {
		y += moveY * speed;
		if (destination.y >= y) {
			moveY = 0;
		}
	}

	if (moveX == 0 && moveY == 0) {
		/*if (++destinationIndex < destinations.size()) {
			float rad = atan2f(destination.y - y, destination.x - x);
			moveX = cosf(rad);
			moveY = sinf(rad);
		}*/
		bulletShotCount = 0;
		bulletWaitTime = 0;
		finishAttack = false;
	}
	Location nowLocation = { x, y };
	SetLocation(nowLocation);
}

void BOSS::CreateBullet(int angle) {
	for (int i = bulletCount; i < BULLET_MAX; i++) {
		if (bullets[i] == nullptr) {
			bullets[i] = new EnemyBullet(x, y, angle, 3.0f, 5, 0x008000);
			bulletCount++;
			bulletShotCount++;
			break;
		}
	}
}

void BOSS::Draw() const {
	if (isActive) {
		DrawRotaGraphF(x, y, 2.0, 0.0, images[enemyMode], TRUE);
	}
	for (int i = 0; i < bulletCount; i++) {
		if (bullets[i] != nullptr) {
			bullets[i]->Draw();
		}
	}
}
