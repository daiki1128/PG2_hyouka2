#include "Enemy.h"
#include "Novice.h"
#include "Resources.h"

Enemy::Enemy(const Vector2& startPos)
    : pos_(startPos),
    speed_({ -3.0f, 0.0f }),   // ← 右から左へ侵入
    width_(64.0f),
    height_(64.0f),
    hitWidth_(50.0f),
    hitHeight_(30.0f),
    isAlive_(true),
    animFrame_(0),
    animTimer_(0),
    state_(State::Enter),
    moveDir_(1),
    shootTimer_(0),
    shootInterval_(90) {
}

void Enemy::Update() {
    if (!isAlive_) return;

    const float kTop = 0.0f;
    const float kBottom = 720.0f;
    const float kEnterEndX = 900.0f;

    switch (state_) {

    case State::Enter:
        // 横移動（画面内へ）
        pos_.x += speed_.x;

        if (pos_.x <= kEnterEndX) {
            pos_.x = kEnterEndX;
            state_ = State::Move;

            // 上下移動用に設定
            speed_.y = 2.0f;
            moveDir_ = 1;
        }
        break;

    case State::Move:
        // 上下移動
        pos_.y += speed_.y * moveDir_;

        if (pos_.y - height_ / 2.0f <= kTop) {
            pos_.y = kTop + height_ / 2.0f;
            moveDir_ = 1;
        }

        if (pos_.y + height_ / 2.0f >= kBottom) {
            pos_.y = kBottom - height_ / 2.0f;
            moveDir_ = -1;
        }
        break;
    }

    // アニメーション
    animTimer_++;
    if (animTimer_ >= kAnimInterval) {
        animTimer_ = 0;
        animFrame_ = (animFrame_ + 1) % 3;
    }

    shootTimer_++;
}

void Enemy::Draw(const Matrix3x3& worldToScreen) const {
    if (!isAlive_) return;

    Vector2 screenPos = Transform(pos_, worldToScreen);

    Novice::DrawSprite(
        static_cast<int>(screenPos.x - width_ / 2.0f),
        static_cast<int>(screenPos.y - height_ / 2.0f),
        graphHandleEnemy[animFrame_],
        2.0f,
        2.0f,
        0.0f,
        WHITE
    );
}

bool Enemy::IsAlive() const {
    return isAlive_;
}

void Enemy::Kill() {
    isAlive_ = false;
}

bool Enemy::IsShootRequested() const {
    return shootTimer_ >= shootInterval_;
}

Vector2 Enemy::GetMuzzlePos() const {
    return { pos_.x - width_ / 2.0f, pos_.y };
}