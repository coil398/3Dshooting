#include "Game.h"
#include "dxlib.h"
#include "Player.h"
#include "Enemy.h"
#include "fps.h"
#include "camera.h"


Game::Game()
{
	//�v���C���[�쐬xyzHP
	player = new Player(0.0f,0.0f,0.0f,0.0f, 100);
	stage = new BackGround();
	//FPS���擾���\������
	fps = new Fps();
	//�J�����I�u�W�F�N�g
	camera = new Camera(*player);
}


Game::~Game()
{
	//�X�e�[�W���f���̍폜
	delete stage;
	//game�I�����A������I�u�W�F�N�g�̃��������J��
	delete player;
	//delete enemy;
	delete fps;
	delete camera;
}

//�Q�[�����s
void Game::Run()
{
	//�v���C���[�̈ړ�
	player->Move();

	//�v���C���[�̉�]
	player->Rot();

	//�J��������֐�
	camera->MoveCamera();

	//�X�e�[�W�̕`��
	stage->Draw();

	//�v���C���[�̕`��
	player->Draw();

	//fps�X�V
	fps->Update();

	//fps�\��
	fps->Draw();

	//�J�E���^�[���₵
	counter++;
}
