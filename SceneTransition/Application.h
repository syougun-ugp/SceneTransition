#pragma once
#include <memory>
#include "SceneManager.h"

class Application
{
public:
	Application();

	// アップデート
	void Update();
private:
	// 閉じる処理を書く
	bool IsClosed()const;
	
	// シーン管理実態
	std::unique_ptr<SceneManager> sceneManager;
};

