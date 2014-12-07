#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Fps.h"
#include "Camera.h"
#include "BackGround.h"

class Game
{
private:
	int old; //前の入力状況
	int nowInput; //現在の入力状況
	int edgeInput; //押されたボタンのみビットが立っている入力値
	int counter = 0;
	Player* player;
	//Enemy* enemy;
	BackGround* stage;
	Fps* fps;
	Camera* camera;
	VECTOR Eye; //カメラの位置
public:
	Game();
	~Game();
	void Input();
	void Run();
};

