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
	//プレイヤーのポインタ
	Player* player;
	//エネミーのポインタ
	Enemy* enemy;
	//ステージのポインタ
	BackGround* stage;
	//FPSのポインタ
	Fps* fps;
	//カメラのポインタ
	Camera* camera;
public:
	Game();
	~Game();
	void Input();
	void Run();
};

