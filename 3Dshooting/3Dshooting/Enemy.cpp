#include "Enemy.h"
#include <DxLib.h>
#include "CheckKeyh.h"
#include <math.h>

Enemy::Enemy(float x, float y, float z,int hp) :Character(x, y, z,hp)
{
	//エネミーのモデルデータ読み込み
	EnemyModelHandle = MV1LoadModel("../materials/model/marisa/marisa_1.04NS.pmx");

	//エネミーのモデルを１８０度回転
	MV1SetRotationXYZ(EnemyModelHandle, VGet(0, 2*DX_PI_F , 0));

	//エネミーの初期位置セット
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
	//3Dモデルの移動
	MV1SetPosition(EnemyModelHandle, pos);
	// ３Ｄモデルの描画  
	MV1DrawModel(EnemyModelHandle);
}
