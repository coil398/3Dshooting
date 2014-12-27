#include "Game.h"
#include "dxlib.h"
#include "Player.h"
#include "Enemy.h"
#include "fps.h"
#include "camera.h"
#include "CheckKeyh.h"
#include "Bullet.h"

Game::Game()
{
	//�v���C���[�쐬xyzHP
	player = new Player(0.0f, 50.0f, 0.0f, 100);
	//�G�l�~�[�쐬xyzHP
	enemy = new Enemy(0.0f, 50.0f, -200.0f, 100);
	//�X�e�[�W�̃I�u�W�F�N�g
	stage = new BackGround();
	//�e�I�u�W�F�N�g
	bullet = new Bullet();
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
	delete enemy;
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

	//�e�̏���Todo
	bullet->Shot(player->vector, enemy->vector);

	//�J�����̈ʒu�X�V
	camera->Move(player->vector, enemy->vector);

	//�X�e�[�W�̕`��
	stage->Draw();

	//�G�l�~�[�̕`��
	enemy->Draw(enemy->vector);

	//�o���b�g�̕`��
	bullet->Draw();

	//�v���C���[�̕`��
	player->Draw(player->vector);

	

	//fps�X�V
	fps->Update();

	//fps�\��
	//fps->Draw(player->vector.x,player->vector.y);

	//�J�E���^�[���₵
	counter++;
}
