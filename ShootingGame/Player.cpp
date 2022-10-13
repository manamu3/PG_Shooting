#include "Player.h"
#include "PadInput.h"
#include "Bullet.h"

Player::Player() {
	images[0] = LoadGraph("");
}

void Player::Update() {
	Move();
	if (PAD_INPUT::GetNowKey() == XINPUT_BUTTON_A) {
		Shot();
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

	x += moveX * speed;
	y += moveY * speed;
}

void Player::Shot() {
	
}

void Player::Draw() const {
	DrawCircle(x, y, 10, 0x0000FF, TRUE);
}

void Player::Hit() {
	
}

bool Player::LifeCheck() {
	return life <= 0;
}

int Player::GetScore() {
	return score;
}