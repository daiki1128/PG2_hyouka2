#include "Camera.h"

Camera::Camera(float windowWidth, float windowHeight)
    : position_{ 0.0f, 0.0f },
    left_(0.0f),
    top_(0.0f),
    right_(windowWidth),
    bottom_(windowHeight),
    viewportLeft_(0.0f),
    viewportTop_(0.0f),
    windowWidth_(windowWidth),
    windowHeight_(windowHeight) {
}

void Camera::SetPosition(const Vector2& pos) {
    position_ = pos;
}

const Vector2& Camera::GetPosition() const {
    return position_;
}

Matrix3x3 Camera::GetWorldToScreenMatrix() const {
    return MakeWorldToScreenMatrix(
        position_,
        left_, top_, right_, bottom_,
        viewportLeft_, viewportTop_,
        windowWidth_, windowHeight_
    );
}