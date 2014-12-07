#include "Game.h"
#include "dxlib.h"
#include "Player.h"
#include "Enemy.h"
#include "fps.h"
#include "camera.h"


Game::Game()
{
	eye = VGet(0.0f,470.0f, -200.0f);
	nowInput = 0;
	//�v���C���[�쐬xyzHP
	player = new Player(0.0f, -5000.0f, 0.0f, 0.0f, 100);
	stage = new BackGround();
	//FPS���擾���\������
	fps = new Fps();
	//�J�����I�u�W�F�N�g
	camera = new Camera(*player,eye);
}


void Game::Input()
{
	old = nowInput;
	nowInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//�V���ɉ����ꂽ�{�^���̃r�b�g���������Ă���l��������
	edgeInput = nowInput & ~old;
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
	Input();

	//�X�e�[�W�̕`��
	stage->Draw();

	//�v���C���[�̏���
	player->Process(&nowInput, &edgeInput, player, eye, stage);

	//�v���C���[�̕`��
	player->Draw();

	//�J�����̏���
	camera->Process(&nowInput, player,&eye,stage);

	//fps�X�V
	fps->Update();

	//fps�\��
	fps->Draw();

	//�J�E���^�[���₵
	counter++;
}
