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
	static void UpdateInput();	//�p�b�h���͂̍X�V

	static int GetPadThumbLX() { return Input.ThumbLX; }	//���X�e�B�b�N��X
	static int GetPadThumbLY() { return -Input.ThumbLY; }	//���X�e�B�b�N��Y
	static int GetNowKey(int key) { return NowKey[key]; }	//�{�^���̓��́i�����ꑱ���Ă�j
	static int GetKeyFlg(int key) { return KeyFlg[key]; }	//�{�^���̓��́i�������u�ԁj
};

