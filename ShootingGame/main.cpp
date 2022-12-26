#include "DxLib.h"
#include "SceneManager.h"
#include "Title.h"
#include "PadInput.h"
#include "ImageManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetMainWindowText("シューティングゲーム（仮）");
	ChangeWindowMode(TRUE);
	SetGraphMode(640, 480, 32);
	SetAlwaysRunFlag(TRUE);
	if (DxLib_Init() == -1) return -1;
	if (ImageManager::LoadGraph() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	SceneManager sceneManager(new Title());

	double nextTime = GetNowCount();

	while (ProcessMessage() == 0 && sceneManager.Update() != nullptr && !(PAD_INPUT::GetNowKey(XINPUT_BUTTON_BACK) == 1)) {
		PAD_INPUT::UpdateInput();
		
		ClearDrawScreen();
		
		sceneManager.Draw();
		
		ScreenFlip();
		
		nextTime += 16.66;
		if (nextTime > GetNowCount()) {
			WaitTimer(nextTime - GetNowCount());
		}

	}
	DxLib_End();
	return 0;
}