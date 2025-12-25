#include "Background.h"
#include "Novice.h"
#include "Resources.h"

Background::Background()
    : screenWidth_(1280.0f),
    screenHeight_(720.0f) {

    layers_[0] = { graphHandleBackground1, 0.0f, 1.0f }; // 一番奥（遅い）
    layers_[1] = { graphHandleBackground2, 0.0f, 2.5f };
    layers_[2] = { graphHandleBackground3, 0.0f, 4.0f }; // 一番手前（速い）
}

void Background::Update() {
    for (auto& layer : layers_) {
        layer.x -= layer.speed;

        // 1枚分左に行ったら右に戻す
        if (layer.x <= -screenWidth_) {
            layer.x += screenWidth_;
        }
    }
}

void Background::Draw() const {
    for (const auto& layer : layers_) {

        // 1枚目
        Novice::DrawSprite(
            static_cast<int>(layer.x),
            0,
            layer.texture,
            1.0f,
            1.0f,
            0.0f,
            WHITE
        );

        // 2枚目（つなぎ用）
        Novice::DrawSprite(
            static_cast<int>(layer.x + screenWidth_),
            0,
            layer.texture,
            1.0f,
            1.0f,
            0.0f,
            WHITE
        );
    }
}