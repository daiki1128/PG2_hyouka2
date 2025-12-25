#include "SceneManager.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ResultScene.h"

SceneManager::SceneManager() {
    ChangeScene(SceneType::Title);
}

SceneManager::~SceneManager() {
   
}

void SceneManager::Update() {
    backGround_.Update();
    currentScene_->Update();
}

void SceneManager::Draw() {
    backGround_.Draw();
    currentScene_->Draw();
}

void SceneManager::ChangeScene(SceneType type, int score) {

    switch (type) {
    case SceneType::Title:
        currentScene_ = std::make_unique<TitleScene>(this);
        break;

    case SceneType::Game:
        currentScene_ = std::make_unique<GameScene>(this);
        break;

    case SceneType::Result:
        currentScene_ = std::make_unique<ResultScene>(this, score);
        break;
    }
}