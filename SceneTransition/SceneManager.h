#pragma once
#include <unordered_map>
#include <memory>
#include "Transition.h"

class IScene;

class SceneManager
{
public:
	SceneManager();

	// ƒV[ƒ“‚ğØ‚è‘Ö‚¦‚é‚Æ‚«‚Ìƒf[ƒ^
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

	// “o˜^íœ
	static void Deregistration(const std::string& name);

	// ƒV[ƒ“‚ğØ‚è‘Ö‚¦‚é
	// Ÿ‚És‚­ƒV[ƒ“‚Ì“o˜^–¼
	void ChangeScene(const ChangeSceneData& changeData);

private:
	// “o˜^
	static void Register(std::shared_ptr<IScene> scene);

	// ŒŸõ‚µ‚Äæ“¾‚·‚é
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

