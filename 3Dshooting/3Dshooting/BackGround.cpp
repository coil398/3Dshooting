#include "BackGround.h"
#include <DxLib.h>


BackGround::BackGround()
{
	//ステージデータ読み込み
	StageModelHandle = MV1LoadModel("../materials/stage/Vual_library/魔法図書館.x");
	//ステージを大きくする
	MV1SetScale(GetModelHandle(), VGet(1000,1000,1000));
	//あたり判定
	//MV1SetupCollInfo(StageModelHandle, -1);
}


BackGround::~BackGround()
{
	// ステージモデルの削除
	MV1DeleteModel(StageModelHandle);
}

//ステージモデルの表示
void BackGround::Draw()
{
	MV1SetPosition(GetModelHandle(), VGet(640.0f,420.0f,-700.0f));

	MV1DrawModel(StageModelHandle);
}

int BackGround::GetModelHandle()
{
	return StageModelHandle;
}
