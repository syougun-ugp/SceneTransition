#pragma once
#include <unordered_map>
#include <memory>
#include "Transition.h"

class IScene;

class SceneManager
{
public:
	SceneManager();

	// シーンを切り替えるときのデータ
	struct ChangeSceneData
	{
		ChangeSceneData() = default;
		ChangeSceneData(const std::string& name,
			const Transition::State fadeInState,
			const Transition::State fadeOutState) :
			name(name),
			fadeInState(fadeInState),
			fadeOutState(fadeOutState){}

		std::string name;
		Transition::State fadeInState;
		Transition::State fadeOutState;
	};
	void Update();

	// 登録削除
	static void Deregistration(const std::string& name);

	// シーンを切り替える
	// 次に行くシーンの登録名
	void ChangeScene(const ChangeSceneData& changeData);

private:
	// 登録
	static void Register(std::shared_ptr<IScene> scene);

	// 検索して取得する
	static std::shared_ptr<IScene> Find(const std::string& name);

	void Init();

	enum class State
	{
		Init,
		Update,
		FadeOut
	};

	static State state;
	static std::shared_ptr<IScene> currentScene;
	static std::shared_ptr<IScene> nextScene;

	static std::unordered_map<std::string, std::shared_ptr<IScene>> sceneData;
	std::unique_ptr<Transition> fadeIn;
	std::unique_ptr<Transition> fadeOut;

	ChangeSceneData changeSceneData;
};

