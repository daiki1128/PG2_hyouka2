#include "BulletManager.h"
#include <algorithm>

void BulletManager::Update() {

    for (auto& bullet : bullets_) {
        bullet.Update();
    }

    // 死んだ弾を削除
    bullets_.erase(
        std::remove_if(
            bullets_.begin(),
            bullets_.end(),
            [](const Bullet& b) { return !b.IsAlive(); }
        ),
        bullets_.end()
    );
}

void BulletManager::Draw(const Matrix3x3& worldToScreen) const {

    for (const auto& bullet : bullets_) {
        bullet.Draw(worldToScreen);
    }
}

void BulletManager::Spawn(const Vector2& startPos) {

    Vector2 velocity{ 12.0f, 0.0f };
    bullets_.emplace_back(startPos, velocity);
}

void BulletManager::CheckCollisionWithEnemies(std::vector<Enemy>& enemies, int& score) {

    for (auto& bullet : bullets_) {
        if (!bullet.IsAlive()) continue;

        for (auto& enemy : enemies) {
            if (!enemy.IsAlive()) continue;

            Vector2 bPos = bullet.GetPos();
            Vector2 ePos = enemy.GetPos();

            bool hitX =
                std::abs(bPos.x - ePos.x) <
                (bullet.GetHitWidth() + enemy.GetHitWidth()) * 0.5f;

            bool hitY =
                std::abs(bPos.y - ePos.y) <
                (bullet.GetHitHeight() + enemy.GetHitHeight()) * 0.5f;

            if (hitX && hitY) {
                bullet.Kill();
                enemy.Kill();
                score += 10;
                break;
            }
        }
    }
}