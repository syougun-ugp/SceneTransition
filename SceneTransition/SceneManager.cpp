#include "SceneManager.h"
#include "TitleManager.h"
#include "GameManager.h"

SceneManager::State SceneManager::state = State::Init;
std::shared_ptr<IScene> SceneManager::currentScene = nullptr;
std::shared_ptr<IScene> SceneManager::nextScene = nullptr;
std::unordered_map<std::string, std::shared_ptr<IScene>> SceneManager::sceneData;

SceneManager::SceneManager():
fadeIn(std::make_unique<Transition>()),
fadeOut(std::make_unique<Transition>()),
changeSceneData()
{
	Register(std::make_shared<TitleManager>(*this));
	Register(std::make_shared<GameManager>(*this));

	currentScene = Find(TitleManager::SceneName);
	fadeIn->Start(Transition::State::BackIn);

}

void SceneManager::Register(std::shared_ptr<IScene> scene)
{
	sceneData.insert(std::make_pair(scene->Name(), scene));

	std::cout << scene->Name() << " 登録" << std::endl;

}

// 登録削除
void SceneManager::Deregistration(const std::string& name)
{
	auto findScene = sceneData.find(name);
	if (findScene == sceneData.end()) return;

	sceneData.erase(findScene);
	std::cout << findScene->second->Name() << " 削除" << std::endl;
}


// 検索して取得する
std::shared_ptr<IScene> SceneManager::Find(const std::string& name)
{
	auto findScene = sceneData.find(name);
	if (findScene == sceneData.end()) return nullptr;

	std::cout << findScene->second->Name() << " 取得" << std::endl;

	return findScene->second;
}


// シーンを切り替える
// 次に行くシーンの登録名
void SceneManager::ChangeScene(const ChangeSceneData& changeData)
{
	nextScene = Find(changeData.name);

	fadeOut->Start(changeData.fadeOutState);

	changeSceneData = changeData;
	state = State::FadeOut;
}

void SceneManager::Init()
{
	if (state != State::Init) return;

	currentScene->Init();
	
	fadeIn->Start(changeSceneData.fadeOutState);

	state = State::Update;
}

void SceneManager::Update()
{
	Init();

	if (state != State::Update) return;

	currentScene->Update();
	currentScene->Render();

	fadeIn->Update();
	fadeOut->Update();

	if (fadeOut->IsEnd())
	{
		currentScene = nextScene;
		state = State::Init;
	}
}