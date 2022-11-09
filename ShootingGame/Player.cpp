#include "Player.h"
#include "PadInput.h"
#include "PlayerBullet.h"
#include "ImageManager.h"

Player::Player() {
	if ((images[0] = LoadGraph("images/player.png")) == -1) {
		throw "プレイヤー画像の読み込みに失敗しました。";
	}
	bullets = new BulletsBase *[BULLET_MAX];
	for (int i = 0; i < BULLET_MAX; i++) {
		bullets[i] = nullptr;
	}
	bulletTime = BULLET_INTERVAL;
	isDamage = false;
	isBlink = false;
	blink = 0;
	blinkType = -15;
	blinkCnt = 0;
	life = 3;
	score = 0;
}

void Player::Update() {
	Move();
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A) {
		if (++bulletTime > BULLET_INTERVAL) {
			Shot();
			bulletTime = 0;
		}
	}
	else {
		bulletTime = BULLET_INTERVAL;
	}
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullets[i] != nullptr) {
			bullets[i]->Update();
			if (!bullets[i]->IsActive()) {
				delete bullets[i];
				bullets[i] = nullptr;
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
	if (inputLX < -DEVIATION) {
		moveX = -1;
	}
	else if (inputLX > DEVIATION) {
		moveX = 1;
	}
	else {
		moveX = 0;
	}

	if (inputLY < -DEVIATION) {
		moveY = -1;
	}
	else if (inputLY > DEVIATION) {
		moveY = 1;
	}
	else {
		moveY = 0;
	}

	float nowSpeed = speed;
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_X) nowSpeed /= 3;
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
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullets[i] == nullptr) {
			bullets[i] = new PlayerBullet(x, y, 5, 3, 0xFFFFFF);
			break;
		}
	}
}

void Player::Draw() const {
	if (isBlink) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, blink);
	}
	DrawGraph(x - PLAYER_SIZE / 2, y - PLAYER_SIZE / 2, images[0], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullets[i] != nullptr) {
			bullets[i]->Draw();
		}
	}
}

void Player::Hit(Location pos) {
	if (HitSphere(pos) && !isDamage && !isBlink) {
		life--;
		blink = 255;
		blinkType = -17;
		blinkCnt = 0;
		isDamage = true;
		isBlink = true;
	}
}

bool Player::LifeCheck() {
	return life <= 0;
}

int Player::GetScore() {
	return score;
}