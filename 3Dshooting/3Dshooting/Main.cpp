#include "DxLib.h"
#include "Game.h"

#define SizeX 1280
#define SizeY 960
#define COLORBITNUM 16

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE); // ウィンドウモードに設定

	SetGraphMode(SizeX, SizeY, COLORBITNUM);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK); //ダブルバッファリングの準備

	Game* game = new Game(); //ゲームクラスのインスタンスを作成

	while ( ProcessMessage() != -1)
	{
		ClearDrawScreen(); //画面をクリアする

		game->Run(); //以下ゲーム内処理をすべてRun()に書く

		ScreenFlip(); //裏画面を表に出す
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}