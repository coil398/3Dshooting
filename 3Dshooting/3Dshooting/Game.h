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
	int old; //前の入力状況
	int nowInput; //現在の入力状況
	int edgeInput; //押されたボタンのみビットが立っている入力値
	//プレイヤーのポインタ
	Player* player;
	//エネミーのポインタ
	Enemy* enemy;
	//ステージのポインタ
	BackGround* stage;
	//弾のポインタ
	//Bullet* bullet;
	//DEBUGのポインタ
	Debug* debug;
	//カメラのポインタ
	Camera* camera;
public:
	Game();
	~Game();
	void Input();
	void Run();
	static int debugger; //デバッグのフラグ
	static int counter;
};

