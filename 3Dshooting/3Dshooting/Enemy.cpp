#include "Enemy.h"
#include <DxLib.h>
#include "CheckKeyh.h"
#include <math.h>

Enemy::Enemy(float x, float y, float z,int hp) :Character(x, y, z,hp)
{
	//�G�l�~�[�̃��f���f�[�^�ǂݍ���
	EnemyModelHandle = MV1LoadModel("../materials/model/���J������/���J�������.pmd");
	if (EnemyModelHandle == -1)return;

	MV1SetScale(EnemyModelHandle, VGet(2, 2, 2));

	AttachIndex = MV1AttachAnim(EnemyModelHandle, 0, -1, FALSE);
	TotalTime = MV1GetAttachAnimTotalTime(EnemyModelHandle, AttachIndex);

	//�G�l�~�[�̃��f�����P�W�O�x��]
	MV1SetRotationXYZ(EnemyModelHandle, VGet(0, 2*DX_PI_F , 0));

	EnemyMaterialNum = MV1GetMaterialNum(EnemyModelHandle);
	for (int i = 0; i < EnemyMaterialNum; i++)
	{
		dotWidth = MV1GetMaterialOutLineDotWidth(EnemyModelHandle, i);
		MV1SetMaterialOutLineDotWidth(EnemyModelHandle, i, dotWidth / 10.0f);
	}
}


Enemy::~Enemy()
{
}

void Enemy::Move(VECTOR playerVector,Enemy* enemy)
{
	theta = atan((enemy->vector.x - playerVector.x) / 200.0f);
	phi = atan((enemy->vector.y - playerVector.y) / (200.0f / cos(theta)));

	MV1SetRotationXYZ(EnemyModelHandle, VGet(-phi, -theta+DX_PI_F, 0));
}

void Enemy::Draw(VECTOR pos)
{
	//3D���f���̈ړ�
	MV1SetPosition(EnemyModelHandle, pos);
	//�A�j���[�V�����ݒ�
	MV1SetAttachAnimTime(EnemyModelHandle, AttachIndex, time);
	// �R�c���f���̕`��  
	MV1DrawModel(EnemyModelHandle);
}
