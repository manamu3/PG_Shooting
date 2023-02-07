#include "GameOver.h"
#include "PadInput.h"
#include "Title.h"

GameOver::GameOver(int _score) {
	score = _score;
}

AbstractScene* GameOver::Update() {
	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_B)) {
		return new Title();
	}

	return this;
}

void GameOver::Draw() const {
	SetFontSize(64);

	DrawString(90, 80, "ゲームオーバー", 0xFF0000);

	SetFontSize(32);
	int strWidth = GetDrawFormatStringWidth("スコア : %d", score);
	DrawFormatString(320 - strWidth / 2, 200, 0xFFFFFF, "スコア : %d", score);

	SetFontSize(22);
	DrawString(232, 350, "PRESS B BUTTON", 0xFF0000);
}