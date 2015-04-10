// -----------------------------------------------
// �V�[���̃g�����W�������� ����
//
// �����ŗl�X�Ȍ��ʂ��R�[�f�B���O���Ă���
// 
// ���݂́A��ԂŌ��ʂ����Ă��邪�A
// �{���́A�I�u�W�F�N�g�𕪂���ق����������͂���
// -----------------------------------------------
#pragma once


class Transition
{
public:
	Transition();

	// ���ʂ̏��
	// ���ʂ������ɒǉ����Ă���
	enum class State
	{
		None,
		BackOut,
		BackIn,
		WhiteOut,
		WhiteIn,
		End,
	};
	
	// ��Ԃ�ݒ肵�ăX�^�[�g����
	void Start(const State state);

	void Update();

	// �I���������̏���
	bool IsEnd();

private:
	// �t�F�[�h���
	State state;


};

