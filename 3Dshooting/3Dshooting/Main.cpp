#include "DxLib.h"
#include "Game.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK); //�_�u���o�b�t�@�����O�̏���

	Game* game = new Game(); //�Q�[���N���X�̃C���X�^���X���쐬

	while ( ProcessMessage() != -1)
	{
		ClearDrawScreen(); //��ʂ��N���A����

		game->Run(); //�ȉ��Q�[�������������ׂ�Run()�ɏ���

		ScreenFlip(); //����ʂ�\�ɏo��
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}