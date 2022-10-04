#include "Pad.h"

#include "DxLib.h"

void Pad::UpdateInput() {
	g_OldKey = g_NowKey;
	g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	g_KeyFlg = g_NowKey & ~g_OldKey;
}

int Pad::GetNowKey() {
	return g_NowKey;
}

int Pad::GetKeyFlg() {
	return g_KeyFlg;
}