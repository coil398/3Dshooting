#include "Game.h"
#include "dxlib.h"
#include "Player.h"
#include "Enemy.h"
#include "Debug.h"
#include "camera.h"
#include "CheckKeyh.h"
#include "Bullet.h"

int counter = 0;
int debugger = 0;

Game::Game()
{
	//�v���C���[�쐬xyzHP
	player = new Player(0.0f, 50.0f, 0.0f, 100, 100);
	//�G�l�~�[�쐬xyzHP
	enemy = new Enemy(0.0f, 50.0f, -200.0f, 500, 500);
	//�X�e�[�W�̃I�u�W�F�N�g
	stage = new BackGround();
	//�e�I�u�W�F�N�g
	//bullet = new Bullet();
	//FPS���擾���\������
	debug = new Debug();
	//�J�����I�u�W�F�N�g
	camera = new Camera();
}



Game::~Game()
{
	//�X�e�[�W���f���̍폜
	delete stage;

	//game�I�����A������I�u�W�F�N�g�Q�̃��������J��
	delete player;
	delete enemy;
	delete debug;
	delete camera;
}

//�Q�[�����s
void Game::Run()
{
	counter++;

	if (CheckKey::Key[KEY_INPUT_F3]==1)
	{
		if (debugger == 0)
			debugger = 1;
		else debugger = 0;
	}

	//�v���C���[�̏���
	player->MotionHandler(player, enemy->vector,player->GetBulletObj()->IsShot());

	//�G�l�~�[�̏���
	enemy->MotionHandler(player->vector, enemy, enemy->GetBulletObj()->IsShot());

	//�v���C���[�e�̏���Todo
	player->GetBulletObj()->Shot(VGet(player->vector.x, player->vector.y + 40.0f, player->vector.z), VGet(enemy->vector.x, enemy->vector.y + 40.0f, enemy->vector.z), player);
	player->GetBulletObj()->Collision(enemy);

	//�G�l�~�[�e�̏���Todo
	enemy->GetBulletObj()->Shot(VGet(enemy->vector.x, enemy->vector.y + 40.0f, enemy->vector.z),VGet(player->vector.x, player->vector.y + 40.0f, player->vector.z), enemy);
	enemy->GetBulletObj()->Collision(player);

	//�J�����̈ʒu�X�V
	camera->Move(player->vector, enemy->vector);

	//�X�e�[�W�̕`��
	stage->Draw();

	//�G�l�~�[�̕`��
	enemy->Draw();

	//�o���b�g�̕`��
	player->GetBulletObj()->Draw();
	enemy->GetBulletObj()->Draw();

	//�v���C���[�̕`��
	player->Draw();

	if (debugger == 1)
	{
		//fps�X�V
		debug->Update();

		//�f�o�b�O���\��
		debug->Draw(*player,*enemy);
	}

	if (player->GetHp() < 0 | enemy->GetHp() < 0)
	{
		return;
	}
}
