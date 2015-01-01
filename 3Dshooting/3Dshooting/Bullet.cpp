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
			//現在位置のベクトルに移動ベクトルを加算
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

//ある位置からある位置への移動ベクトルを求める関数
void Bullet::Calculator(int i,VECTOR start,VECTOR target)
{
	//弾の位置をセット
	bulletLocation[i] = VGet(start.x, start.y + 45.0f, start.z);
	//現在地からターゲットへの方向ベクトル
	direction[i] = VGet(target.x - start.x, target.y - start.y, target.z - start.z);
	//方向ベクトルを正規化
	direction[i] = VNorm(direction[i]);
	//１処理ごとの移動ベクトル
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
				//使用されていないバレット配列のフラグをたてていく
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