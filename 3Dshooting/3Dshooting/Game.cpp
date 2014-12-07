#include "Game.h"
#include "dxlib.h"
#include "Player.h"
#include "Enemy.h"
#include "fps.h"
#include "camera.h"


Game::Game()
{
	Eye = VGet(1.0f, 1.0f, 1.0f);
	nowInput = 0;
	//プレイヤー作成xyzHP
	player = new Player(0.0f, 0.0f, 0.0f, 0.0f, 100);
	stage = new BackGround();
	//FPSを取得し表示する
	fps = new Fps();
	//カメラオブジェクト
	camera = new Camera(Eye);
}


void Game::Input()
{
	old = nowInput;
	nowInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//新たに押されたボタンのビットだけ立っている値を代入する
	edgeInput = nowInput & ~old;
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
	Input();

	player->Process();

	//プレイヤーの移動
	player->Move();

	//プレイヤーの回転
	player->Rot();

	//カメラ操作関数
	camera->CameraControl(*player);

	//ステージの描画
	stage->Draw();

	//プレイヤーの描画
	player->Draw();

	//fps更新
	fps->Update();

	//fps表示
	fps->Draw();

	//カウンター増やし
	counter++;
}
