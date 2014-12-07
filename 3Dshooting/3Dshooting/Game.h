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
	Player* player;
	//Enemy* enemy;
	BackGround* stage;
	Fps* fps;
	Camera* camera;
	VECTOR Eye; //�J�����̈ʒu
public:
	Game();
	~Game();
	void Input();
	void Run();
};

