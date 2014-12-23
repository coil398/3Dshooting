#include "Game.h"
#include "dxlib.h"
#include "Player.h"
#include "Enemy.h"
#include "fps.h"
#include "camera.h"
#include "CheckKeyh.h"

Game::Game()
{
	//�v���C���[�쐬xyzHP
	player = new Player(0.0f, 50.0f, 0.0f, 100);
	//�G�l�~�[�쐬xyzHP
	enemy = new Enemy(0.0f, 50.0f, -200.0f, 100);
	stage = new BackGround();
	//FPS���擾���\������
	fps = new Fps();
	//�J�����I�u�W�F�N�g
	camera = new Camera();
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
	//�v���C���[�̏���
	player->Move(player, enemy->vector);

	//�G�l�~�[�̏���
	enemy->Move(player->vector, enemy);

	//�J�����̈ʒu�X�V
	camera->Move(player->vector, enemy->vector);

	//�X�e�[�W�̕`��
	stage->Draw();

	//�v���C���[�̕`��
	player->Draw(player->vector);

	//�G�l�~�[�̕`��
	enemy->Draw(enemy->vector);

	//fps�X�V
	fps->Update();

	//fps�\��
	fps->Draw(player->vector.x,player->vector.y);

	//�J�E���^�[���₵
	counter++;
}
