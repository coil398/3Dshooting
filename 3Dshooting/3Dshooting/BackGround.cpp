#include "BackGround.h"
#include <DxLib.h>


BackGround::BackGround()
{
	//�X�e�[�W�f�[�^�ǂݍ���
	StageModelHandle = MV1LoadModel("../materials/stage/�o���̂Ȃ��L��/�o���̂Ȃ��L��.pmx");
	//�X�J�C�h�[��
	//BackGroundHandle = MV1LoadModel("../materials/stage/sky_dome_11_pmx/sky_dome_11.pmx");
	//�X�e�[�W��傫������
	MV1SetScale(StageModelHandle, VGet(50, 50, 50));
	//MV1SetScale(BackGroundHandle, VGet(10, 10, 10));
	//�����蔻��
	MV1SetupCollInfo(StageModelHandle, -1);
	//Fiffuse�𒲐�
	SetLightDifColor(GetColorF(1.0f, 1.0f, 1.0f, 0.0f));
	//Ambient�𒲐�
	SetLightAmbColor(GetColorF(1.0f, 1.0f, 1.0f, 0.0f));
	//Specular�𒲐�
	SetLightSpcColor(GetColorF(1.0f, 1.0f, 1.0f, 0.0f));
}


BackGround::~BackGround()
{
	// �X�e�[�W���f���̍폜
	MV1DeleteModel(StageModelHandle);
	//MV1DeleteModel(BackGroundHandle);
}

//�X�e�[�W���f���̕\��
void BackGround::Draw()
{
	MV1DrawModel(StageModelHandle);
	//MV1DrawModel(BackGroundHandle);
}

int BackGround::GetModelHandle()
{
	return StageModelHandle;
}
