#pragma once
#include "IScene.h"

class GameManager:public IScene
{
public:
	GameManager(SceneManager& sceneManager);

	void Init();
	void Update();
	void Render();

	static const std::string SceneName;
private:


};

