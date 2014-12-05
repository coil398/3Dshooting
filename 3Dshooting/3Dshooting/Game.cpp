#include "Game.h"
#include "dxlib.h"
#include "Player.h"
#include "Enemy.h"
#include "Vector3.h"
#include "fps.h"
#include "camera.h"


Game::Game()
{
	//プレイヤー作成xyzHP
	player = new Player(640.0f, 420.0f, -700.0f, 100);
	//FPSを取得し表示する
	fps = new Fps();
	//カメラオブジェクト
	camera = new Camera(player);
}


Game::~Game()
{
	//game終了時、作ったオブジェクトのメモリを開放
	delete player;
	//delete enemy;
	delete fps;
	delete camera;
}

//ゲーム実行
void Game::Run()
{
	player->Move();

	player->Rot();

	player->Draw();

	//fps更新
	fps->Update();

	//fps表示
	fps->Draw();

	counter++;
}
