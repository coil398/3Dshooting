#include "DxLib.h"
#include "Game.h"
#include "Enemy.h"
#include "fps.h"
#include "CheckKeyh.h"

#define SizeX 1280
#define SizeY 960
#define COLORBITNUM 16
#include "Player.h"


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ɐݒ�

	for (int i = 0; i < 256; i++)
		CheckKey::Key[i] = 0;

	//�`��T�C�Y�ύX
	SetGraphMode(SizeX, SizeY, COLORBITNUM);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK); //�_�u���o�b�t�@�����O�̏���


	Game* game = new Game(); //�Q�[���N���X�̃C���X�^���X���쐬

	//�Q�[��������
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && CheckKey::gpUpdateKey() == 0)
	{
		game->Run();
	}

	//game�N���X�̃��������
	delete game;

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
