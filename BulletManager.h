#pragma once
#include <vector>
#include "Bullet.h"
#include "Enemy.h"

class BulletManager {
public:
    void Update();
    void Draw(const Matrix3x3& worldToScreen) const;

    //弾の発生処理
    void Spawn(const Vector2& startPos);

    void CheckCollisionWithEnemies(std::vector<Enemy>& enemies, int& score);

private:
    std::vector<Bullet> bullets_;
};