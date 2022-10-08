#include "DxLib.h"
#include "SceneManager.h"
#include "Title.h"
#include "PadInput.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetMainWindowText("");
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	SceneManager sceneManager(new Title());

	while (ProcessMessage() == 0 && sceneManager.Update() != nullptr && !(PAD_INPUT::GetNowKey() == XINPUT_BUTTON_BACK)) {
		PAD_INPUT::UpdateInput();
		
		ClearDrawScreen();

		sceneManager.Draw();
		
		ScreenFlip();
	}
	DxLib_End();
	return 0;
}