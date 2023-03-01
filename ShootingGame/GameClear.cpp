#include "GameClear.h"
#include "PadInput.h"
#include "Title.h"

GameClear::GameClear(int _score) {
	score = _score;
}

AbstractScene* GameClear::Update() {
	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_B)) {
		return new Title();
	}

	return this;
}

void GameClear::Draw() const {
	SetFontSize(64);

	DrawString(120, 80, "ゲームクリア", 0xFFFF00);

	SetFontSize(32);
	int strWidth = GetDrawFormatStringWidth("スコア : %d", score);
	DrawFormatString(320 - strWidth / 2, 200, 0xFFFFFF, "スコア : %d", score);

	SetFontSize(22);
	DrawString(232, 350, "PRESS B BUTTON", 0xFF0000);
}