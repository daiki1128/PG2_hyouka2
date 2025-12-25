#pragma once
#include <array>

class Background {
public:
    Background();

    void Update();
    void Draw() const;

private:
    struct Layer {
        int texture;
        float x;
        float speed;
    };

    static constexpr int kLayerCount = 3;
    std::array<Layer, kLayerCount> layers_;

    float screenWidth_;
    float screenHeight_;
};