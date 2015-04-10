#include "GameManager.h"


const std::string GameManager::SceneName = "GameMain";

GameManager::GameManager(SceneManager& sceneManager) :
IScene(SceneName, sceneManager)
{
}

void GameManager::Init()
{
	std::cout << Name() << " ������" << std::endl;
}

void GameManager::Update()
{
	std::cout << Name() << " �A�b�v�f�[�g" << std::endl;

}

void GameManager::Render()
{
	std::cout << Name() << " �`��" << std::endl;

}
