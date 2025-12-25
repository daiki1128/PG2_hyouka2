#include "ResultScene.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "Novice.h"

ResultScene::ResultScene(SceneManager* sceneManager, int score)
    : sceneManager_(sceneManager),
    score_(score) {
}

void ResultScene::Update() {
    // タイトルへ戻る
    if (InputManager::Instance().IsTrigger(DIK_SPACE)) {
        sceneManager_->ChangeScene(SceneType::Title);
        return;
    }

    // リトライ
    if (InputManager::Instance().IsTrigger(DIK_RETURN)) {
        sceneManager_->ChangeScene(SceneType::Game);
        return;
    }
}

void ResultScene::Draw() {
    Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);

    Novice::ScreenPrintf(520, 240, "RESULT");
    Novice::ScreenPrintf(520, 300, "SCORE : %d", score_);

    Novice::ScreenPrintf(420, 400, "ENTER : RETRY");
    Novice::ScreenPrintf(420, 440, "SPACE : TITLE");
}