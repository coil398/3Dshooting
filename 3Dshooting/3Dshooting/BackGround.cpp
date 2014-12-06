#include "BackGround.h"
#include <DxLib.h>


BackGround::BackGround()
{
	//�X�e�[�W�f�[�^�ǂݍ���
	StageModelHandle = MV1LoadModel("../materials/stage/Vual_library/���@�}����.x");
	//�X�e�[�W��傫������
	MV1SetScale(GetModelHandle(), VGet(1000,1000,1000));
	//�����蔻��
	//MV1SetupCollInfo(StageModelHandle, -1);
}


BackGround::~BackGround()
{
	// �X�e�[�W���f���̍폜
	MV1DeleteModel(StageModelHandle);
}

//�X�e�[�W���f���̕\��
void BackGround::Draw()
{
	MV1SetPosition(GetModelHandle(), VGet(640.0f,420.0f,-700.0f));

	MV1DrawModel(StageModelHandle);
}

int BackGround::GetModelHandle()
{
	return StageModelHandle;
}
