#pragma once

#include "DxLib.h"

#define BUTTONS 16

class PAD_INPUT {
private:
	static int NowKey;
	static int OldKey;
	static int KeyFlg;
	static XINPUT_STATE Input;

public:
	static void UpdateInput();	//�p�b�h���͂̍X�V
	static int GetPadThumbLX();	//���X�e�B�b�N��X
	static int GetPadThumbLY();	//���X�e�B�b�N��Y
	static int GetNowKey();		//�{�^���̓���
};

