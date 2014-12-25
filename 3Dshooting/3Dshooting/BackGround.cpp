#include "BackGround.h"
#include <DxLib.h>


BackGround::BackGround()
{
	//ステージデータ読み込み
	StageModelHandle = MV1LoadModel("../materials/stage/出口のない廊下/出口のない廊下.pmx");
	//スカイドーム
	//BackGroundHandle = MV1LoadModel("../materials/stage/sky_dome_11_pmx/sky_dome_11.pmx");
	//ステージを大きくする
	MV1SetScale(StageModelHandle, VGet(20, 20, 20));
	//MV1SetScale(BackGroundHandle, VGet(10, 10, 10));
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
	//MV1DeleteModel(BackGroundHandle);
}

//ステージモデルの表示
void BackGround::Draw()
{
	MV1DrawModel(StageModelHandle);
	//MV1DrawModel(BackGroundHandle);
}

int BackGround::GetModelHandle()
{
	return StageModelHandle;
}
