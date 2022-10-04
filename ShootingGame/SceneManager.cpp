#include "SceneManager.h"

AbstractScene* SceneManager::Update() {
	AbstractScene* nextScene = mScene->Update();
	if (nextScene != mScene) {
		delete mScene;
		mScene = nextScene;
	}

	return nextScene;
}

void SceneManager::Draw() const {
	mScene->Draw();
}