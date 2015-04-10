#include "GameManager.h"


const std::string GameManager::SceneName = "GameMain";

GameManager::GameManager(SceneManager& sceneManager) :
IScene(SceneName, sceneManager)
{
}

void GameManager::Init()
{
	std::cout << Name() << " 初期化" << std::endl;
}

void GameManager::Update()
{
	std::cout << Name() << " アップデート" << std::endl;

}

void GameManager::Render()
{
	std::cout << Name() << " 描画" << std::endl;

}
