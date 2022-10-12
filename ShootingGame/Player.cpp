#include "Player.h"
#include "PadInput.h"

Player::Player() {
	images[0] = LoadGraph("");
}

void Player::Update() {
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

void Player::Draw() const {
	DrawGraph(x, y, images[0], TRUE);
}

void Player::Hit() {
	
}

bool Player::LifeCheck() {
	return life <= 0;
}

int Player::GetScore() {
	return score;
}