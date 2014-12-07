#include "BackGround.h"
#include <DxLib.h>


BackGround::BackGround()
{
	//�X�e�[�W�f�[�^�ǂݍ���
	StageModelHandle = MV1LoadModel("../materials/stage/Vual_library/���@�}����.x");
	//�X�e�[�W��傫������
	MV1SetScale(GetModelHandle(), VGet(500,500,500));
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
}

//�X�e�[�W���f���̕\��
void BackGround::Draw()
{
	MV1DrawModel(BackGroundHandle);
	MV1DrawModel(StageModelHandle);
}

int BackGround::GetModelHandle()
{
	return StageModelHandle;
}
