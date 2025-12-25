#pragma once

enum class SceneType {
	Title,
	Game,
	Result
};

class Scene {
public:

	virtual ~Scene() = default;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};