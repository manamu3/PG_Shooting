#include "ImageManager.h"
#include "DxLib.h"

int ImageManager::shogiImages[2][8];

int ImageManager::LoadGraph() {
	if (LoadDivGraph("images/shogi1.png", 8, 8, 1, 40, 40, shogiImages[0]) == -1) return -1;
	if (LoadDivGraph("images/shogi2.png", 8, 8, 1, 40, 40, shogiImages[1]) == -1) return -1;

	return 0;
}