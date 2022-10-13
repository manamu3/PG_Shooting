#include "PadInput.h"

int PAD_INPUT::NowKey = -1;
int PAD_INPUT::OldKey = -1;
int PAD_INPUT::KeyFlg = -1;
XINPUT_STATE PAD_INPUT::Input;

void PAD_INPUT::UpdateInput() {
	GetJoypadXInputState(DX_INPUT_KEY_PAD1, &Input);
	if (NowKey != -1)
	{
		OldKey = NowKey;
	}
	for (int i = 0; i < BUTTONS; i++)
	{
		if (Input.Buttons[i])
		{
			NowKey = i;
			break;
		}
		NowKey = -1;
	}
	KeyFlg = NowKey & ~OldKey;
}

int PAD_INPUT::GetPadThumbLX() {
	return Input.ThumbLX;
}

int PAD_INPUT::GetPadThumbLY() {
	return -Input.ThumbLY;
}

int PAD_INPUT::GetNowKey() {
	return NowKey;
}