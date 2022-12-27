#pragma once

#include "DxLib.h"

#define BUTTONS 16

class PAD_INPUT {
private:
	static int NowKey[BUTTONS];
	static int OldKey[BUTTONS];
	static int KeyFlg[BUTTONS];
	static XINPUT_STATE Input;

public:
	static void UpdateInput();	//パッド入力の更新

	static int GetPadThumbLX() { return Input.ThumbLX; }	//左スティックのX
	static int GetPadThumbLY() { return -Input.ThumbLY; }	//左スティックのY
	static int GetNowKey(int key) { return NowKey[key]; }	//ボタンの入力（押され続けてる）
	static int GetKeyFlg(int key) { return KeyFlg[key]; }	//ボタンの入力（押した瞬間）
};

