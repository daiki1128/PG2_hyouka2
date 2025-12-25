#pragma once
#include "Scene.h"

class SceneManager;

class ResultScene : public Scene {
public:
    ResultScene(SceneManager* sceneManager, int score);

    void Update() override;
    void Draw() override;

private:
    SceneManager* sceneManager_;
    int score_;
};