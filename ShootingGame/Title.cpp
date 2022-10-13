#include "Title.h"

#include "DxLib.h"
#include "GameMain.h"

Title::Title() {

}

AbstractScene* Title::Update() {
	return new GameMain();
}

void Title::Draw() const {
	
}