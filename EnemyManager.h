#pragma once
#include <vector>
#include "Enemy.h"
#include "Matrix3x3.h"

class EnemyManager {
public:
    EnemyManager();

    void Update();
    void Draw(const Matrix3x3& worldToScreen) const;

    // 敵生成
    void Spawn();

    // 当たり判定用
    std::vector<Enemy>& GetEnemies();

private:
    std::vector<Enemy> enemies_;

    int spawnTimer_;
    int spawnInterval_;

    static constexpr int kMaxEnemies = 3;
};