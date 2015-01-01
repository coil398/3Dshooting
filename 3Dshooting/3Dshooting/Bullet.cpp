#include "Bullet.h"
#include "Character.h"
#include "Player.h"

Bullet::Bullet()
{
	i = 0;
	isShot = 0;
	bulletSpeed = 5.0f;
	LoadDivGraph("../materials/bullet/Bullet01.png", 5, 5, 1, 64, 64, bulletImage);
}


Bullet::~Bullet()
{
}

void Bullet::Draw()
{
	for (k = 0; k < BULLET;k++)
	{
		if (bullet[k] == 1)
		{
			DrawBillboard3D(bulletLocation[k], 0.5f, 0.5f, 10.0f, 0.0f, bulletImage[k%5], TRUE);
		}
	}
}

void Bullet::ShotController(VECTOR start,VECTOR target)
{
	for (j = 0; j < BULLET;j++)
	{
		if (bullet[j]==1)
		{
			//���݈ʒu�̃x�N�g���Ɉړ��x�N�g�������Z
			bulletLocation[j] = VAdd(bulletLocation[j], move[j]);
		}

		if (bulletLocation[j].z < -210.0f)
		{
			bullet[j] = 0;
			isGraze[j] = 1;
		}
	}
}

int Bullet::IsShot()
{
	return isShot;
}

void Bullet::Shot(VECTOR start, VECTOR target,Player* player)
{
	isShot++;

	key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (isShot >= 10)
	{

		NormalShot(start,target,player);
	}

	ShotController(start, target);
}

void Bullet::Shot(VECTOR start, VECTOR target, Enemy* enemy)
{
	//Todo
}

//����ʒu���炠��ʒu�ւ̈ړ��x�N�g�������߂�֐�
void Bullet::Calculator(int i,VECTOR start,VECTOR target)
{
	//�e�̈ʒu���Z�b�g
	bulletLocation[i] = VGet(start.x, start.y + 45.0f, start.z);
	//���ݒn����^�[�Q�b�g�ւ̕����x�N�g��
	direction[i] = VGet(target.x - start.x, target.y - start.y, target.z - start.z);
	//�����x�N�g���𐳋K��
	direction[i] = VNorm(direction[i]);
	//�P�������Ƃ̈ړ��x�N�g��
	move[i] = VGet(bulletSpeed*direction[i].x, bulletSpeed*direction[i].y, bulletSpeed*direction[i].z);
}

void Bullet::NormalShot(VECTOR start,VECTOR target,Character* character)
{
	if (character->GetMp()>5)
	{
		if (key & PAD_INPUT_1)
		{
			if (bullet[i] == 0)
			{
				//�g�p����Ă��Ȃ��o���b�g�z��̃t���O�����ĂĂ���
				bullet[i] = 1;
				isCol[i] = 0;
				isGraze[i] = 0;
				Calculator(i, start, target);
				isShot = 0;
				character->AddMp(-5);
			}
			i++;
			if (i == BULLET - 1)
			{
				i = 0;
			}
		}
	}
}