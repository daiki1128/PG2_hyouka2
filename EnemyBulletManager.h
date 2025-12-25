#pragma once
#include <vector>
#include "EnemyBullet.h"
#include "Player.h"

class EnemyBulletManager {
public:
    void Update();
    void Draw(const Matrix3x3& worldToScreen) const;

    void Spawn(const Vector2& pos);

    void CheckCollisionWithPlayer(class Player& player);

private:
    std::vector<EnemyBullet> bullets_;
};