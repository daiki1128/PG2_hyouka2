#pragma once
#include "Scene.h"

class SceneManager;

class TitleScene : public Scene {
public:
    TitleScene(SceneManager* sceneManager);

    void Update() override;
    void Draw() override;

private:
    SceneManager* sceneManager_;
};