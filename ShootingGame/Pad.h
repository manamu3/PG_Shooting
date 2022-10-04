#pragma once
class Pad
{
private:
	int g_OldKey;
	int g_NowKey;
	int g_KeyFlg;

public:
	void UpdateInput();
	int GetNowKey();
	int GetKeyFlg();
};

