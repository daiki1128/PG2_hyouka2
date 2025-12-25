#pragma once
#include "Vector2.h"
#include "Matrix3x3.h"

class Player {
public:
    Player(const Vector2& startPos);

    //更新処理
    void Update();

    //描画処理
    void Draw(const Matrix3x3& worldToScreen) const;

    void Damage(int value);

    //ゲッター
    Vector2 GetPos() const { return pos_; }
    float GetWidth() const { return width_; }
    float GetHeight() const { return height_; }
    float GetHitWidth() const { return hitWidth_; }
    float GetHitHeight() const { return hitHeight_; }

    int GetHP() const;
    int GetMaxHP() const;

    bool IsAlive() const;
    void Kill();

    // 弾発射要求
    bool IsShootRequested() const;

    //弾のゲッター
    Vector2 GetMuzzlePosition() const;

private:
    Vector2 pos_;
    float width_;
    float height_;
    float hitWidth_;
    float hitHeight_;
    float speed_;

    bool isAlive_;

    bool shootRequested_;

    int animFrame_;
    int animTimer_;
    static constexpr int kAnimInterval = 8;

    int hp_;
    int maxHp_;
};