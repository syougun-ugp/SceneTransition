#pragma once
#include <string>
#include <iostream>
#include "SceneManager.h"

class IScene
{
public:
	// �V�[���̖��O�A�V�[���Ǘ��̎��ԎQ��
	IScene(const std::string &name, SceneManager& sceneManager) :
		name(name),
		sceneManager(sceneManager)
	{

	}

	virtual ~IScene() = default;

	// ������
	virtual void Init() = 0;

	// �A�b�v�f�[�g
	virtual void Update() = 0;

	// �`��
	virtual void Render() = 0;

	// �V�[���̖��O���擾
	const std::string Name()const{ return name; }

protected:
	// �V�[����؂�ւ���Ƃ��Ɏg�p
	void ChangeScene(const SceneManager::ChangeSceneData& changeSceneData)
	{
		sceneManager.ChangeScene(changeSceneData);
	}
private:
	const std::string name;
	SceneManager& sceneManager;

};

