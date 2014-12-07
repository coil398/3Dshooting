#include "BackGround.h"
#include <DxLib.h>


BackGround::BackGround()
{
	//ステージデータ読み込み
	StageModelHandle = MV1LoadModel("../materials/stage/Vual_library/魔法図書館.x");
	//ステージを大きくする
	MV1SetScale(GetModelHandle(), VGet(500,500,500));
	//あたり判定
	MV1SetupCollInfo(StageModelHandle, -1);
	//Fiffuseを調整
	SetLightDifColor(GetColorF(1.0f, 1.0f, 1.0f, 0.0f));
	//Ambientを調整
	SetLightAmbColor(GetColorF(1.0f, 1.0f, 1.0f, 0.0f));
	//Specularを調整
	SetLightSpcColor(GetColorF(1.0f, 1.0f, 1.0f, 0.0f));
}


BackGround::~BackGround()
{
	// ステージモデルの削除
	MV1DeleteModel(StageModelHandle);
}

//ステージモデルの表示
void BackGround::Draw()
{
	MV1DrawModel(BackGroundHandle);
	MV1DrawModel(StageModelHandle);
}

int BackGround::GetModelHandle()
{
	return StageModelHandle;
}
