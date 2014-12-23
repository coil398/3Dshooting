#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Fps.h"
#include "Camera.h"
#include "BackGround.h"

class Game
{
private:
	int old; //�O�̓��͏�
	int nowInput; //���݂̓��͏�
	int edgeInput; //�����ꂽ�{�^���̂݃r�b�g�������Ă�����͒l
	int counter = 0;
	//�v���C���[�̃|�C���^
	Player* player;
	//�G�l�~�[�̃|�C���^
	Enemy* enemy;
	//�X�e�[�W�̃|�C���^
	BackGround* stage;
	//FPS�̃|�C���^
	Fps* fps;
	//�J�����̃|�C���^
	Camera* camera;
public:
	Game();
	~Game();
	void Input();
	void Run();
};

