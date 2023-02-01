#include "Player.h"
#include "PadInput.h"
#include "PlayerBullet.h"
#include "ImageManager.h"
#include "Enemy.h"

Player::Player(Enemy** _enemy, int* _enemyMax) {
	if ((images[0] = LoadGraph("images/player.png")) == -1) {
		throw "プレイヤー画像の読み込みに失敗しました。";
	}
	bullets = new BulletsBase *[BULLET_MAX];
	for (int i = 0; i < BULLET_MAX; i++) {
		bullets[i] = nullptr;
	}
	itemCnt[ITEM_TYPE::POWER_UP] = 0;

	enemy = _enemy;
	enemyMax = _enemyMax;

	bulletTime = BULLET_INTERVAL;
	bulletDamagePoint = 3;
	isDamage = false;
	isBlink = false;
	isTripleBullet = false;
	isHomingBullet = false;
	blink = 0;
	blinkType = -15;
	blinkCnt = 0;
	life = 3;
	score = 0;

	Init(320, 420, 0, 0, 5, 30);
}

void Player::Update() {
	Move();
	if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_A) == 1) {
		if (++bulletTime > BULLET_INTERVAL) {
			Shot();
			bulletTime = 0;
		}
	}
	else {
		bulletTime = BULLET_INTERVAL;
	}
	for (int i = 0; i < bulletCount; i++) {
		if (bullets[i] != nullptr) {
			bullets[i]->Update();
			if (!bullets[i]->IsActive()) {
				DeleteBullet(i);
			}
		}
	}

	if (isBlink) {
		isDamage = false;
		blink += blinkType;
		if (blink <= 0 || blink >= 255) {
			blinkType *= -1;
			if (++blinkCnt > 5) isBlink = false;
		}
	}
}

void Player::Move() {
	int inputLX = PAD_INPUT::GetPadThumbLX();
	int inputLY = PAD_INPUT::GetPadThumbLY();
	if (inputLX < -DEVIATION || PAD_INPUT::GetNowKey(XINPUT_BUTTON_DPAD_LEFT)) {
		moveX = -1;
	}
	else if (inputLX > DEVIATION || PAD_INPUT::GetNowKey(XINPUT_BUTTON_DPAD_RIGHT)) {
		moveX = 1;
	}
	else {
		moveX = 0;
	}

	if (inputLY < -DEVIATION || PAD_INPUT::GetNowKey(XINPUT_BUTTON_DPAD_UP)) {
		moveY = -1;
	}
	else if (inputLY > DEVIATION || PAD_INPUT::GetNowKey(XINPUT_BUTTON_DPAD_DOWN)) {
		moveY = 1;
	}
	else {
		moveY = 0;
	}

	float nowSpeed = speed;
	if (PAD_INPUT::GetNowKey(XINPUT_BUTTON_X) == 1) nowSpeed /= 3;
	float newX = x + moveX * nowSpeed;
	if (newX < PLAYER_SIZE / 2 || newX > 640 - PLAYER_SIZE / 2) newX = x;
	float newY = y + moveY * nowSpeed;
	if (newY < PLAYER_SIZE / 2 || newY > 480 - PLAYER_SIZE / 2) newY = y;
	x = newX;
	y = newY;

	Location nowLocation = { x, y };
	SetLocation(nowLocation);
}

void Player::Shot() {
	for (int i = bulletCount; i < BULLET_MAX; i++) {
		if (bullets[i] == nullptr) {
			bullets[i] = new PlayerBullet(x, y, 5, bulletDamagePoint, 0xFFFFFF, enemy, *enemyMax, isHomingBullet);
			bulletCount++;
			break;
		}
	}
	if (isTripleBullet) {
		int bulletNum = 0;
		for (int i = bulletCount; i < BULLET_MAX; i++) {
			if (bullets[i] == nullptr) {
				bulletCount++;
				if (bulletNum == 0) {
					bullets[i] = new PlayerBullet(x, y, 0.3f, -0.7f, 5, bulletDamagePoint, 0xFFFFFF);
				}
				else {
					bullets[i] = new PlayerBullet(x, y, -0.3f, -0.7f, 5, bulletDamagePoint, 0xFFFFFF);
					break;
				}
				bulletNum++;
			}
		}
	}
}

void Player::Draw() const {
	if (isBlink) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, blink);
	}
	DrawGraph(x - PLAYER_SIZE / 2, y - PLAYER_SIZE / 2, images[0], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	for (int i = 0; i < bulletCount; i++) {
		if (bullets[i] != nullptr) {
			bullets[i]->Draw();
		}
	}

	DrawFormatString(0, 0, 0xFFFFFF, "Score: %d", score);
	DrawFormatString(0, 30, 0xFFFFFF, "Life : %d", life);
}

bool Player::Hit(Location pos) {
	if (HitSphere(pos) && !isDamage && !isBlink) {
		life--;
		blink = 255;
		blinkType = -17;
		blinkCnt = 0;
		isDamage = true;
		isBlink = true;
		return true;
	}

	return false;
}

void Player::HitItem(ITEM_TYPE item) {
	if (++itemCnt[item] % 5 == 0) {
		switch (item) {
		case ITEM_TYPE::POWER_UP:
			if (++bulletDamagePoint >= 30) {
				isTripleBullet = true;
			}
			else if (bulletDamagePoint >= 10) {
				isHomingBullet = true;
			}
			break;
		}
	}

}