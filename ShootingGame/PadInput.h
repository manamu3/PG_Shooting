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
	static int GetPadThumbLX();	//左スティックのX
	static int GetPadThumbLY();	//左スティックのY
	static int GetNowKey(int key);	//ボタンの入力
};

