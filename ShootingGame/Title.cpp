#include "Title.h"

#include "DxLib.h"
#include "GameMain.h"
#include "PadInput.h"

Title::Title() {
	cursorY = 0;
	cursorMove = false;
}

AbstractScene* Title::Update() {
	if (PAD_INPUT::GetPadThumbLY() < -3000) {
		if (!cursorMove) {
			if (--cursorY < 0) cursorY = 1;
			cursorMove = true;
		}
	}
	else if (PAD_INPUT::GetPadThumbLY() > 3000) {
		if (!cursorMove) {
			if (++cursorY > 1) cursorY = 0;
			cursorMove = true;
		}
	}
	else {
		cursorMove = false;
	}

	if (PAD_INPUT::GetKeyFlg(XINPUT_BUTTON_A) == TRUE) {
		if (cursorY == 0) {
			return new GameMain();
		}
		/*else if (cursorY == 1) {

		}*/
		else {
			return nullptr;
		}
	}
	return this;
}

void Title::Draw() const {
	SetFontSize(80);
	DrawString(217, 50, "Title", 0xFFFFFF);

	SetFontSize(32);
	DrawString(287, 280, "Game", 0xFFFFFF);
	//DrawString(287, 320, "Help", 0xFFFFFF);
	DrawString(287, 360, "End", 0xFFFFFF);

	DrawTriangle(250, 275 + cursorY * 80, 280, 295 + cursorY * 80, 250, 315 + cursorY * 80, 0xFF0000, TRUE);
}