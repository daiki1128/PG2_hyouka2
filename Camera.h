#pragma once
#include "Vector2.h"
#include "Matrix3x3.h"

class Camera {
public:
    Camera(float windowWidth, float windowHeight);

    // 更新
    void SetPosition(const Vector2& pos);
    const Vector2& GetPosition() const;

    // 行列取得
    Matrix3x3 GetWorldToScreenMatrix() const;

private:
    Vector2 position_;

    // オーソグラフィック範囲（ワールド）
    float left_;
    float top_;
    float right_;
    float bottom_;

    // ビューポート（スクリーン）
    float viewportLeft_;
    float viewportTop_;
    float windowWidth_;
    float windowHeight_;
};