#include "PadInput.h"

int PAD_INPUT::NowKey[BUTTONS] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int PAD_INPUT::OldKey[BUTTONS] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int PAD_INPUT::KeyFlg[BUTTONS] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
XINPUT_STATE PAD_INPUT::Input;

void PAD_INPUT::UpdateInput() {
	GetJoypadXInputState(DX_INPUT_KEY_PAD1, &Input);
	for (int i = 0; i < BUTTONS; i++)
	{
		OldKey[i] = NowKey[i];
		NowKey[i] = Input.Buttons[i];
		KeyFlg[i] = NowKey[i] & ~OldKey[i];
	}
}