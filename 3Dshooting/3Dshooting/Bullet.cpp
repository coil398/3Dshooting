#include "Bullet.h"
#include "Character.h"
#include "Player.h"
#include "Game.h"

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
			DrawBillboard3D(bulletLocation[k], 0.5f, 0.5f, 10.0f, 0.0f, bulletImage[0], TRUE);
		}
		if (bullet[k] == 2)
		{
			DrawBillboard3D(bulletLocation[k], 0.5f, 0.5f, 10.0f, 0.0f, bulletImage[1], TRUE);
		}
	}
}

void Bullet::ShotController(VECTOR start,VECTOR target)
{
	if (counter % 10 == 0)
	{
		for (j = 0; j < BULLET; j++)
		{
			if (bullet[j] == 2 & bulletLocation[j].z < -50 & bulletLocation[j].z > -150)
			{
				Calculator(j, bulletLocation[j], target);
			}
		}
	}

	for (j = 0; j < BULLET;j++)
	{
		if (bullet[j]==1)
		{
			//現在位置のベクトルに移動ベクトルを加算
			bulletLocation[j] = VAdd(bulletLocation[j], move[j]);
		}

		if (bullet[j] == 2)
		{
			bulletLocation[j] = VAdd(bulletLocation[j], move[j]);
		}

		if (bulletLocation[j].z < -210.0f | bulletLocation[j].z > 10.0f)
		{
			bullet[j] = 0;
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
		NormalShot(start, target, player);
		HomingShot(start, target, player);
	}

	ShotController(start, target);

}

void Bullet::Shot(VECTOR start, VECTOR target, Enemy* enemy)
{
	enFlag = 2;
	if (counter % 10 == 0)
	{
		NormalShot(start, target,enemy);
		HomingShot(start, target, enemy);
	}

	ShotController(start, target);

}

//ある位置からある位置への移動ベクトルを求める関数
void Bullet::Calculator(int i,VECTOR start,VECTOR target)
{
	//弾の位置をセット
	bulletLocation[i] = start;
	//現在地からターゲットへの方向ベクトル
	direction[i] = VGet(target.x - start.x, target.y - start.y, target.z - start.z);
	//方向ベクトルを正規化
	direction[i] = VNorm(direction[i]);
	//１処理ごとの移動ベクトル
	move[i] = VGet(bulletSpeed*direction[i].x, bulletSpeed*direction[i].y, bulletSpeed*direction[i].z);
}

void Bullet::NormalShot(VECTOR start,VECTOR target,Player* player)
{
	if (player->GetMp()>5)
	{
		if (key & PAD_INPUT_1)
		{
			if (bullet[i] == 0)
			{
				//使用されていないバレット配列のフラグをたてていく
				bullet[i] = 1;
				isGraze[i] = 0;
				Calculator(i, start, target);
				isShot = 0;
				player->AddMp(-5);
			}
			i++;
			if (i == BULLET - 1)
			{
				i = 0;
			}
		}
	}
}

void Bullet::HomingShot(VECTOR start, VECTOR target, Player* player)
{
	if (player->GetMp()>10)
	{
		if (key & PAD_INPUT_2)
		{
			if (bullet[i] == 0)
			{
				//使用されていないバレット配列のフラグをたてていく
				bullet[i] = 2;
				isGraze[i] = 0;
				Calculator(i, start, target);
				isShot = 0;
				player->AddMp(-5);
			}
			i++;
			if (i == BULLET - 1)
			{
				i = 0;
			}
		}
	}
}

void Bullet::NormalShot(VECTOR start, VECTOR target, Enemy* enemy)
{
	if (enemy->GetMp()>5)
	{
		if (enFlag == 1)
		{
			if (bullet[i] == 0)
			{
				//使用されていないバレット配列のフラグをたてていく
				bullet[i] = 1;
				isGraze[i] = 0;
				Calculator(i, start, target);
				isShot = 0;
				enemy->AddMp(-5);
			}
			i++;
			if (i == BULLET - 1)
			{
				i = 0;
			}
		}
	}
}

void Bullet::HomingShot(VECTOR start, VECTOR target, Enemy* enemy)
{
	if (enemy->GetMp()>10)
	{
		if (enFlag == 2)
		{
			if (bullet[i] == 0)
			{
				//使用されていないバレット配列のフラグをたてていく
				bullet[i] = 2;
				isGraze[i] = 0;
				Calculator(i, start, target);
				isShot = 0;
				enemy->AddMp(-10);
			}
			i++;
			if (i == BULLET - 1)
			{
				i = 0;
			}
		}
	}
}

void Bullet::Collision(Character* character)
{
	for (l = 0; l < BULLET; l++)
	{
		if (bullet[l] == 1 | bullet[l] == 2)
		{
			colVector = VSub(VGet(character->vector.x, character->vector.y + 40.0f, character->vector.z), bulletLocation[l]);
			distVector = colVector.x * colVector.x + colVector.y * colVector.y + colVector.z * colVector.z;
			if (isGraze[l] == 0 & distVector  < 250)
			{
				character->AddMp(5);
			}
			if (distVector < 20)
			{
				bullet[l] = 0;
				character->AddHp(-10);
			}
		}
	}
}