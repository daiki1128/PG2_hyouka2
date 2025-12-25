#include "EnemyManager.h"
#include <algorithm>
#include <cstdlib>
#include <cmath>

EnemyManager::EnemyManager()
    : spawnTimer_(0),
    spawnInterval_(120) {
}

void EnemyManager::Update() {

    spawnTimer_++;

    //リスポーン管理
    if (spawnTimer_ >= spawnInterval_
        && enemies_.size() < kMaxEnemies) {

        Spawn();
        spawnTimer_ = 0;
    }

    //各Enemy更新
    for (auto& enemy : enemies_) {
        enemy.Update();
    }

    //死亡Enemyを削除
    enemies_.erase(
        std::remove_if(
            enemies_.begin(),
            enemies_.end(),
            [](const Enemy& e) { return !e.IsAlive(); }
        ),
        enemies_.end()
    );
}

void EnemyManager::Draw(const Matrix3x3& worldToScreen) const {
    for (const auto& enemy : enemies_) {
        enemy.Draw(worldToScreen);
    }
}

void EnemyManager::Spawn() {
    const float spawnX = 1400.0f;
    const float minY = 64.0f;
    const float maxY = 720.0f - 64.0f;
    const float enemyHeight = 64.0f;

    float spawnY = 0.0f;
    bool valid = false;

    
    for (int i = 0; i < 10 && !valid; i++) {

        spawnY = minY + static_cast<float>(rand()) /
            RAND_MAX * (maxY - minY);

        valid = true;

        
        for (const auto& enemy : enemies_) {
            if (std::abs(spawnY - enemy.GetPos().y) < enemyHeight) {
                valid = false;
                break;
            }
        }
    }

    if (valid) {
        enemies_.emplace_back(Vector2{ spawnX, spawnY });
    }
}

std::vector<Enemy>& EnemyManager::GetEnemies() {
    return enemies_;
}