#pragma once
#include <memory>
#include "SceneManager.h"

class Application
{
public:
	Application();

	// �A�b�v�f�[�g
	void Update();
private:
	// ���鏈��������
	bool IsClosed()const;
	
	// �V�[���Ǘ�����
	std::unique_ptr<SceneManager> sceneManager;
};

