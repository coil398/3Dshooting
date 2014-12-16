#include "Game.h"
#include "dxlib.h"
#include "Player.h"
#include "Enemy.h"
#include "fps.h"
#include "camera.h"


Game::Game()
{
	//プレイヤー作成xyzHP
	player = new Player(0.0f, -5000.0f, 0.0f, 0.0f, 100);
	stage = new BackGround();
	//FPSを取得し表示する
	fps = new Fps();
	//カメラオブジェクト
	camera = new Camera(*player,eye);
}



Game::~Game()
{
	//ステージモデルの削除
	delete stage;
	//game終了時、作ったオブジェクトのメモリを開放
	delete player;
	//delete enemy;
	delete fps;
	delete camera;
}

//ゲーム実行
void Game::Run()
{
	//ステージの描画
	stage->Draw();

	//プレイヤーの処理

	//プレイヤーの描画
	player->Draw();

	//fps更新
	fps->Update();

	//fps表示
	fps->Draw();

	//カウンター増やし
	counter++;
}
