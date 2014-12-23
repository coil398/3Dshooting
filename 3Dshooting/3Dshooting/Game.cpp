#include "Game.h"
#include "dxlib.h"
#include "Player.h"
#include "Enemy.h"
#include "fps.h"
#include "camera.h"
#include "CheckKeyh.h"

Game::Game()
{
	//プレイヤー作成xyzHP
	player = new Player(0.0f, 50.0f, 0.0f, 100);
	//エネミー作成xyzHP
	enemy = new Enemy(0.0f, 50.0f, -200.0f, 100);
	stage = new BackGround();
	//FPSを取得し表示する
	fps = new Fps();
	//カメラオブジェクト
	camera = new Camera();
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
	//プレイヤーの処理
	player->Move(player, enemy->vector);

	//エネミーの処理
	enemy->Move(player->vector, enemy);

	//カメラの位置更新
	camera->Move(player->vector, enemy->vector);

	//ステージの描画
	stage->Draw();

	//プレイヤーの描画
	player->Draw(player->vector);

	//エネミーの描画
	enemy->Draw(enemy->vector);

	//fps更新
	fps->Update();

	//fps表示
	fps->Draw(player->vector.x,player->vector.y);

	//カウンター増やし
	counter++;
}
