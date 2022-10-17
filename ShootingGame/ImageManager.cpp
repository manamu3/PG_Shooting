#include "ImageManager.h"
#include "DxLib.h"

ImageManager::ImageManager() {
	if (LoadDivGraph("images/shogi1.png", 8, 8, 1, 40, 40, shogiImages[0]) == -1) {
		throw "‰æ‘œ‚Ì“Ç‚İ‚İ‚É¸”s‚µ‚Ü‚µ‚½B";
	}
	if (LoadDivGraph("images/shogi2.png", 8, 8, 1, 40, 40, shogiImages[1]) == -1) {
		throw "‰æ‘œ‚Ì“Ç‚İ‚İ‚É¸”s‚µ‚Ü‚µ‚½B";
	}
}