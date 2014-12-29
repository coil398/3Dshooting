#include "DxLib.h"
#include "Game.h"
#include "Enemy.h"
#include "Debug.h"
#include "CheckKeyh.h"

#define SizeX 1280
#define SizeY 960
#define COLORBITNUM 16
#include "Player.h"


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE); // ウィンドウモードに設定

	for (int i = 0; i < 256; i++)
		CheckKey::Key[i] = 0;

	//描画サイズ変更
	SetGraphMode(SizeX, SizeY, COLORBITNUM);

	//Zバッファを有効にする
	SetUseZBuffer3D(TRUE);

	//Zバッファの書き込みを有効にする
	SetWriteZBuffer3D(TRUE);

	//アンチエイリアスの設定
	SetFullSceneAntiAliasingMode(4, 2);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK); //ダブルバッファリングの準備


	Game* game = new Game(); //ゲームクラスのインスタンスを作成

	//ゲーム内処理
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && CheckKey::gpUpdateKey() == 0)
	{
		game->Run();
	}

	//gameクラスのメモリ解放
	delete game;

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
