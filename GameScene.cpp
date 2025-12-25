#include "GameScene.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "Resources.h"
#include "Novice.h"

constexpr int kHpBarX = 80;
constexpr int kHpBarY = 20;
constexpr int kHpBarWidth = 250;
constexpr int kHpBarHeight = 40;

GameScene::GameScene(SceneManager* sceneManager)
    : sceneManager_(sceneManager),
    camera_(1280.0f, 720.0f),
    player_({ 200.0f, 400.0f }),
    score_(0),
    isGameOver_(false) {
}

void GameScene::Update() {

    camera_.SetPosition({ 0.0f, 0.0f });

    player_.Update();

    if (player_.IsShootRequested()) {
        bulletManager_.Spawn(player_.GetMuzzlePosition());
    }

    bulletManager_.Update();

    enemyManager_.Update();

    for (auto& enemy : enemyManager_.GetEnemies()) {
        if (!enemy.IsAlive()) continue;

        if (enemy.IsShootRequested()) {
            enemyBulletManager_.Spawn(enemy.GetMuzzlePos());
            enemy.ResetShootTimer();
        }
    }

    enemyBulletManager_.Update();

    //自機の弾と敵
    bulletManager_.CheckCollisionWithEnemies(enemyManager_.GetEnemies(), score_);

    //敵の弾と自機
    enemyBulletManager_.CheckCollisionWithPlayer(player_);

    //自機と敵
    if (player_.IsAlive()) {
        for (auto& enemy : enemyManager_.GetEnemies()) {
            if (!enemy.IsAlive()) continue;

            Vector2 pPos = player_.GetPos();
            Vector2 ePos = enemy.GetPos();

            if (std::abs(pPos.x - ePos.x) < (player_.GetHitWidth() + enemy.GetHitWidth()) / 2.0f && 
                std::abs(pPos.y - ePos.y) < (player_.GetHitHeight() + enemy.GetHitHeight()) / 2.0f) {
                
                player_.Damage(1);
                enemy.Kill();
                score_ += 10;
                break;
            }
        }
    }

    if (score_ >= 200) {
        isGameOver_ = true;
    }

    if (!player_.IsAlive()) {
        sceneManager_->ChangeScene(SceneType::Result, score_);
        return;
    }

    if (isGameOver_) {
        sceneManager_->ChangeScene(SceneType::Result, score_);
        return;
    }
}

void GameScene::Draw() {
    Matrix3x3 worldToScreen = camera_.GetWorldToScreenMatrix();

    enemyBulletManager_.Draw(worldToScreen);

    enemyManager_.Draw(worldToScreen);

    bulletManager_.Draw(worldToScreen);

    player_.Draw(worldToScreen);

    Novice::DrawSprite(
        static_cast<int>(0.0f),
        static_cast<int>(0.0f),
        graphHandleHp,
        2.0f,
        2.0f,
        0.0f,
        WHITE
    );

    //枠(背景）
    Novice::DrawBox(
        kHpBarX,
        kHpBarY,
        kHpBarWidth,
        kHpBarHeight,
        0.0f,
        WHITE,
        kFillModeWireFrame
    );

    //現在HP割合
    float hpRate =
        static_cast<float>(player_.GetHP()) /
        static_cast<float>(player_.GetMaxHP());

    int currentWidth =
        static_cast<int>(kHpBarWidth * hpRate);

    //中身
    Novice::DrawBox(
        kHpBarX,
        kHpBarY,
        currentWidth,
        kHpBarHeight,
        0.0f,
        GREEN,
        kFillModeSolid
    );
    
}