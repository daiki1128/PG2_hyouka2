#pragma once
#include "Vector2.h"
#include "Matrix3x3.h"

class Bullet {
public:
    Bullet(const Vector2& startPos, const Vector2& velocity);

    void Update();
    void Draw(const Matrix3x3& worldToScreen) const;

    bool IsAlive() const;
    void Kill();

    const Vector2& GetPos() const;
    float GetWidth() const { return width_; }
    float GetHeight() const { return height_; }
    float GetHitWidth() const { return hitWidth_; }
    float GetHitHeight() const { return hitHeight_; }

private:
    Vector2 pos_;
    Vector2 velocity_;
    float width_;
    float height_;
    float hitWidth_;
    float hitHeight_;
    bool isAlive_;
};