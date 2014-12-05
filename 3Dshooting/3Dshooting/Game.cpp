#include "Game.h"
#include "dxlib.h"
#include "Player.h"
#include "Enemy.h"
#include "Vector3.h"
#include "fps.h"
#include "camera.h"


Game::Game()
{
	//�v���C���[�쐬xyzHP
	player = new Player(640.0f, 420.0f, -700.0f, 100);
	//FPS���擾���\������
	fps = new Fps();
	//�J�����I�u�W�F�N�g
	camera = new Camera(player);
}


Game::~Game()
{
	//game�I�����A������I�u�W�F�N�g�̃��������J��
	delete player;
	//delete enemy;
	delete fps;
	delete camera;
}

//�Q�[�����s
void Game::Run()
{
	player->Move();

	player->Rot();

	player->Draw();

	//fps�X�V
	fps->Update();

	//fps�\��
	fps->Draw();

	counter++;
}
