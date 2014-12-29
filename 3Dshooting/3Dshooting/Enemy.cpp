#include "Enemy.h"
#include <DxLib.h>
#include "CheckKeyh.h"
#include <math.h>
#include "Game.h"

Enemy::Enemy(float x, float y, float z,int hp,int mp) :Character(x, y, z,hp,mp)
{
	//エネミーのモデルデータ読み込み
	EnemyModelHandle = MV1LoadModel("../materials/model/霧雨魔理沙/霧雨魔理沙箒.pmd");
	if (EnemyModelHandle == -1)return;

	//HPゲージ読み込み
	hpGaugeHandle = LoadGraph("../materials/gauge/hpgauge.png");

	MV1SetScale(EnemyModelHandle, VGet(2, 2, 2));

	attachIndex = MV1AttachAnim(EnemyModelHandle, 0, -1, FALSE);
	totalTime = MV1GetAttachAnimTotalTime(EnemyModelHandle, attachIndex);

	//エネミーのモデルを１８０度回転
	MV1SetRotationXYZ(EnemyModelHandle, VGet(0, 2*DX_PI_F , 0));

	EnemyMaterialNum = MV1GetMaterialNum(EnemyModelHandle);
	for (int i = 0; i < EnemyMaterialNum; i++)
	{
		dotWidth = MV1GetMaterialOutLineDotWidth(EnemyModelHandle, i);
		MV1SetMaterialOutLineDotWidth(EnemyModelHandle, i, dotWidth / 10.0f);
	}

	enBullet = new Bullet();

	hpRatio = hp;
}


Enemy::~Enemy()
{
}

void Enemy::Move(VECTOR playerVector,Enemy* enemy,int isShot)
{
	theta = atan((enemy->vector.x - playerVector.x) / 200.0f);
	phi = atan((enemy->vector.y - playerVector.y) / (200.0f / cos(theta)));

	MV1SetRotationXYZ(EnemyModelHandle, VGet(-phi, -theta+DX_PI_F, 0));

	//3Dモデルの移動
	MV1SetPosition(EnemyModelHandle, enemy->vector);
}

void Enemy::Draw()
{
	// ３Ｄモデルの描画  
	MV1DrawModel(EnemyModelHandle);

	DrawModiBillboard3D(VGet(vector.x + 50.0f, vector.y + 50.0f, vector.z), vector.x, vector.y - 20.0f, vector.x + 100 * (GetHp() / hpRatio), vector.y - 20.0f, vector.x + 100 * (GetHp() / hpRatio) , vector.y - 10, vector.x, vector.y - 10, hpGaugeHandle, FALSE);

}

void Enemy::MotionHandler(VECTOR playerVector, Enemy* enemy,int isShot)
{
	Move(playerVector, enemy, isShot);

	if (Game::counter % 10 == 0)
	{
		if (GetMp()<100)
		{
			AddMp(1);
		}
		AddHp(-10);
	}

	//アニメーション処理
	MV1SetAttachAnimTime(EnemyModelHandle, attachIndex, time);
}

Bullet* Enemy::GetBulletObj()
{
	return enBullet;
}