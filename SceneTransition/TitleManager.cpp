#include "TitleManager.h"
#include "GameManager.h"

const std::string TitleManager::SceneName = "Title";

TitleManager::TitleManager(SceneManager& sceneManager) :
IScene(SceneName, sceneManager)
{
}

void TitleManager::Init()
{
	std::cout << Name() << " 初期化" << std::endl;
}

void TitleManager::Update()
{
	std::cout << Name() << " アップデート" << std::endl;

	/*
	if (条件分)
	{
		ChangeScene(SceneManager::ChangeSceneData(
			GameManager::SceneName, Transition::State::BackIn, Transition::State::WhiteOut));
	}
	*/

	ChangeScene(SceneManager::ChangeSceneData(
		GameManager::SceneName, Transition::State::BackIn, Transition::State::WhiteOut));
}

void TitleManager::Render()
{
	std::cout << Name() << " 描画" << std::endl;

}
