#pragma once
#include "Vector2.h"
#include "Matrix3x3.h"

class Enemy {
public:
    Enemy(const Vector2& startPos);

    void Update();
    void Draw(const Matrix3x3& worldToScreen) const;

    bool IsAlive() const;
    void Kill();

    Vector2 GetPos() const { return pos_; }
    float GetWidth() const { return width_; }
    float GetHeight() const { return height_; }
    float GetHitWidth() const { return hitWidth_; }
    float GetHitHeight() const { return hitHeight_; }

    bool IsShootRequested() const;
    Vector2 GetMuzzlePos() const;

    void ResetShootTimer() { shootTimer_ = 0; }

private:

    enum class State {
        Enter,   // 横から侵入
        Move     // 上下移動
    };

    Vector2 pos_;
    Vector2 speed_;
    int moveDir_;
    float width_;
    float height_;
    float hitWidth_;
    float hitHeight_;
    bool isAlive_;

    int animFrame_;
    int animTimer_;
    static constexpr int kAnimInterval = 8;

    State state_;

    int shootTimer_;
    int shootInterval_;
};