#include "DxLib.h"
#include "Game.h"
#include "Enemy.h"
#include "fps.h"
#include "CheckKeyh.h"

#define SizeX 1280
#define SizeY 960
#define COLORBITNUM 16


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int counter = 0;
	ChangeWindowMode(TRUE); // ウィンドウモードに設定

	for (int i = 0; i < 256; i++)
		CheckKey::Key[i] = 0;

	//描画サイズ変更
	SetGraphMode(SizeX, SizeY, COLORBITNUM);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK); //ダブルバッファリングの準備

	Game* game = new Game(); //ゲームクラスのインスタンスを作成
	Enemy* enemy = new Enemy(640.0f, 480.0f, -700.0f, 100);
	Fps *fps = new Fps();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && CheckKey::gpUpdateKey() == 0)
	{

		enemy->Control();

		enemy->Draw();

		fps->Update();
		fps->Draw();

		counter++;
	}

	delete game;
	delete enemy;

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
