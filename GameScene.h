#pragma once
#include "Scene.h"
#include "Player.h"
#include "BulletManager.h"
#include "Matrix3x3.h"
#include "Camera.h"
#include "EnemyManager.h"
#include "EnemyBulletManager.h"

class SceneManager;

class GameScene : public Scene {
public:
    GameScene(SceneManager* sceneManager);

    void Update() override;
    void Draw() override;

private:
    SceneManager* sceneManager_;

    Player player_;
    BulletManager bulletManager_;

    Camera camera_;

    EnemyManager enemyManager_;

    EnemyBulletManager enemyBulletManager_;

    int score_;
    bool isGameOver_;
};