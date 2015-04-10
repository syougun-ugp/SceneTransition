#include "Application.h"

Application::Application():
sceneManager(std::make_unique<SceneManager>())
{
}

void Application::Update()
{
	/*
	while (IsClosed())
	{
		sceneManager->Update();
	}
	*/

	for (int i = 0; i < 10; i++)
	{
		sceneManager->Update();
	}

}

// ���鏈��������
bool Application::IsClosed()const
{
	return true;
}