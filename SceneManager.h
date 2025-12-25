#pragma once
#include "Scene.h"
#include "Background.h"
#include <memory>

class SceneManager {
public:

	SceneManager();
	~SceneManager();

	void Update();

	void Draw();

	void ChangeScene(SceneType type, int score = 0);

private:
	std::unique_ptr<Scene> currentScene_;

	Background backGround_;
};