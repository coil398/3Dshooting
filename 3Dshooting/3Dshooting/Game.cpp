#include "Game.h"
#include "dxlib.h"
#include "Player.h"
#include "Enemy.h"
#include "Debug.h"
#include "camera.h"
#include "CheckKeyh.h"
#include "Bullet.h"

int Game::counter = 0;
int Game::debugger = 0;

Game::Game()
{
	//プレイヤー作成xyzHP
	player = new Player(0.0f, 50.0f, 0.0f, 100, 50);
	//エネミー作成xyzHP
	enemy = new Enemy(0.0f, 50.0f, -200.0f, 1500, 500);
	//ステージのオブジェクト
	stage = new BackGround();
	//弾オブジェクト
	//bullet = new Bullet();
	//FPSを取得し表示する
	debug = new Debug();
	//カメラオブジェクト
	camera = new Camera();
}



Game::~Game()
{
	//ステージモデルの削除
	delete stage;

	//game終了時、作ったオブジェクト群のメモリを開放
	delete player;
	delete enemy;
	delete debug;
	delete camera;
}

//ゲーム実行
void Game::Run()
{
	Game::counter++;

	if (CheckKey::Key[KEY_INPUT_F3]==1)
	{
		if (debugger == 0)
			debugger = 1;
		else debugger = 0;
	}

	//プレイヤーの処理
	player->MotionHandler(player, enemy->vector,player->GetBulletObj()->IsShot());

	//エネミーの処理
	enemy->MotionHandler(player->vector, enemy, enemy->GetBulletObj()->IsShot());

	//プレイヤー弾の処理Todo
	player->GetBulletObj()->Shot(player->vector, enemy->vector, player);

	//エネミー弾の処理Todo
	enemy->GetBulletObj()->Shot(player->vector, enemy->vector,enemy);

	//カメラの位置更新
	camera->Move(player->vector, enemy->vector);

	//ステージの描画
	stage->Draw();

	//エネミーの描画
	enemy->Draw();

	//バレットの描画
	player->GetBulletObj()->Draw();
	enemy->GetBulletObj()->Draw();

	//プレイヤーの描画
	player->Draw();

	if (debugger == 1)
	{
		//fps更新
		debug->Update();

		//デバッグ情報表示
		debug->Draw(*player,*enemy);
	}
}
