#pragma once
#include "IScene.h"

class TitleManager:public IScene
{
public:
	TitleManager(SceneManager& sceneManager);

	void Init();
	void Update();
	void Render();

	static const std::string SceneName;
private:

};

