#include "TitleManager.h"
#include "GameManager.h"

const std::string TitleManager::SceneName = "Title";

TitleManager::TitleManager(SceneManager& sceneManager) :
IScene(SceneName, sceneManager)
{
}

void TitleManager::Init()
{
	std::cout << Name() << " ������" << std::endl;
}

void TitleManager::Update()
{
	std::cout << Name() << " �A�b�v�f�[�g" << std::endl;

	/*
	if (������)
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
	std::cout << Name() << " �`��" << std::endl;

}
