#include "ImageManager.h"
#include "DxLib.h"

ImageManager::ImageManager() {
	if (LoadDivGraph("images/shogi1.png", 8, 8, 1, 40, 40, shogiImages[0]) == -1) {
		throw "画像の読み込みに失敗しました。";
	}
	if (LoadDivGraph("images/shogi2.png", 8, 8, 1, 40, 40, shogiImages[1]) == -1) {
		throw "画像の読み込みに失敗しました。";
	}
}