#include "BackGround.h"
#include <DxLib.h>


BackGround::BackGround()
{
	//�X�e�[�W�f�[�^�ǂݍ���
	StageModelHandle = MV1LoadModel("../materials/stage/�o���̂Ȃ��L��/�o���̂Ȃ��L��.pmx");
	//�X�e�[�W��傫������
	MV1SetScale(StageModelHandle, VGet(100, 100, 100));
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
	MV1DrawModel(StageModelHandle);
	
}

int BackGround::GetModelHandle()
{
	return StageModelHandle;
}
