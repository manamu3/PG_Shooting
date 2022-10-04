#include "DxLib.h"
#include "SceneManager.h"
#include "Title.h"
#include "Pad.h"

Pad pad;

SceneManager sceneManager(new Title());

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetMainWindowText("");
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0 && sceneManager.Update() != nullptr && !(pad.GetKeyFlg() & PAD_INPUT_START)) {
		pad.UpdateInput();

		sceneManager.Draw();

		ClearDrawScreen();
		
		ScreenFlip();
	}
	DxLib_End();
	return 0;
}