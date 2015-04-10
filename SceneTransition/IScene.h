#pragma once
#include <string>
#include <iostream>
#include "SceneManager.h"

class IScene
{
public:
	// シーンの名前、シーン管理の実態参照
	IScene(const std::string &name, SceneManager& sceneManager) :
		name(name),
		sceneManager(sceneManager)
	{

	}

	virtual ~IScene() = default;

	// 初期化
	virtual void Init() = 0;

	// アップデート
	virtual void Update() = 0;

	// 描画
	virtual void Render() = 0;

	// シーンの名前を取得
	const std::string Name()const{ return name; }

protected:
	// シーンを切り替えるときに使用
	void ChangeScene(const SceneManager::ChangeSceneData& changeSceneData)
	{
		sceneManager.ChangeScene(changeSceneData);
	}
private:
	const std::string name;
	SceneManager& sceneManager;

};

