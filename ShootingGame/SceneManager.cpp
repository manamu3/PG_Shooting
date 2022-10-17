#include "SceneManager.h"

AbstractScene* SceneManager::Update() {
	try {
		AbstractScene* nextScene = mScene->Update();
		if (nextScene != mScene) {
			delete mScene;
			mScene = nextScene;

			return nextScene;
		}
	}
	catch(const char* err) {
		return nullptr;
	}
}

void SceneManager::Draw() const {
	mScene->Draw();
}