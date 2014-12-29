#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Debug.h"
#include "Camera.h"
#include "BackGround.h"
#include "Bullet.h"

class Game
{
private:
	int old; //�O�̓��͏�
	int nowInput; //���݂̓��͏�
	int edgeInput; //�����ꂽ�{�^���̂݃r�b�g�������Ă�����͒l
	//�v���C���[�̃|�C���^
	Player* player;
	//�G�l�~�[�̃|�C���^
	Enemy* enemy;
	//�X�e�[�W�̃|�C���^
	BackGround* stage;
	//�e�̃|�C���^
	//Bullet* bullet;
	//DEBUG�̃|�C���^
	Debug* debug;
	//�J�����̃|�C���^
	Camera* camera;
public:
	Game();
	~Game();
	void Input();
	void Run();
	static int debugger; //�f�o�b�O�̃t���O
	static int counter;
};

