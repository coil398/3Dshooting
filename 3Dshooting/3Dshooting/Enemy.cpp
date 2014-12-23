#include "Enemy.h"
#include <DxLib.h>
#include "CheckKeyh.h"
#include <math.h>

Enemy::Enemy(float x, float y, float z,int hp) :Character(x, y, z,hp)
{
	//�G�l�~�[�̃��f���f�[�^�ǂݍ���
	EnemyModelHandle = MV1LoadModel("../materials/model/marisa/marisa_1.04NS.pmx");

	//�G�l�~�[�̃��f�����P�W�O�x��]
	MV1SetRotationXYZ(EnemyModelHandle, VGet(0, 2*DX_PI_F , 0));

	//�G�l�~�[�̏����ʒu�Z�b�g
	MV1SetPosition(EnemyModelHandle, vector);
}


Enemy::~Enemy()
{
}

void Enemy::Move(VECTOR playerVector,Enemy* enemy)
{
	theta = atan((enemy->vector.x - playerVector.x) / 200.0f);
	phi = atan((enemy->vector.y - playerVector.y) / (200.0f / cos(theta)));

	MV1SetRotationXYZ(EnemyModelHandle, VGet(-phi, DX_PI_F, 0));
}

void Enemy::Draw(VECTOR pos)
{
	//3D���f���̈ړ�
	MV1SetPosition(EnemyModelHandle, pos);
	// �R�c���f���̕`��  
	MV1DrawModel(EnemyModelHandle);
}
