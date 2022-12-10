#include "PadInput.h"

int PAD_INPUT::NowKey[BUTTONS] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
int PAD_INPUT::OldKey[BUTTONS] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
int PAD_INPUT::KeyFlg[BUTTONS] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
XINPUT_STATE PAD_INPUT::Input;

void PAD_INPUT::UpdateInput() {
	GetJoypadXInputState(DX_INPUT_KEY_PAD1, &Input);
	for (int i = 0; i < BUTTONS; i++)
	{
		if (NowKey[i] != -1) {
			OldKey[i] = NowKey[i];
		}
		if (Input.Buttons[i] == 1)
		{
			NowKey[i] = 1;
		}
		else {
			NowKey[i] = -1;
		}
		KeyFlg[i] = NowKey[i] & ~OldKey[i];
	}
}

int PAD_INPUT::GetPadThumbLX() {
	return Input.ThumbLX;
}

int PAD_INPUT::GetPadThumbLY() {
	return -Input.ThumbLY;
}

int PAD_INPUT::GetNowKey(int key) {
	return NowKey[key];
}