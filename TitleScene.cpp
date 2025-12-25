#include "TitleScene.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "Novice.h"
#include "GameScene.h"

TitleScene::TitleScene(SceneManager* sceneManager)
	: sceneManager_(sceneManager) {
}

void TitleScene::Update() {
	if (InputManager::Instance().IsTrigger(DIK_SPACE)) {
		sceneManager_->ChangeScene(SceneType::Game, 0);
	}
}

void TitleScene::Draw() {
	Novice::ScreenPrintf(500, 300, "PRESS SPACE", 40.0f, WHITE);
}