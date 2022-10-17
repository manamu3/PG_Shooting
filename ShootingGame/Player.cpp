#include "Player.h"
#include "PadInput.h"
#include "Bullet.h"
#include "ImageManager.h"

Player::Player() {
	images[0] = GetImage(0, 0);
	bullets = new Bullet[BULLET_MAX];
	bulletTime = BULLET_INTERVAL;
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
		if (bullets[i].IsEnable()) {
			bullets[i].Update();
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
}

void Player::Shot() {
	for (int i = 0; i < BULLET_MAX; i++) {
		if (!bullets[i].IsEnable()) {
			bullets[i].Initialize(x, y, 0, -1, 5, 3, 0xFFFFFF);
			break;
		}
	}
}

void Player::Draw() const {
	DrawGraph(x - PLAYER_SIZE / 2, y - PLAYER_SIZE / 2, images[0], TRUE);
	//DrawCircle(x, y, 10, 0x0000FF, TRUE);
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullets[i].IsEnable()) {
			bullets[i].Draw();
		}
	}
}

void Player::Hit() {
	
}

bool Player::LifeCheck() {
	return life <= 0;
}

int Player::GetScore() {
	return score;
}