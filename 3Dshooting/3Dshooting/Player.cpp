#include "Player.h"
#include "Character.h"
#include "CheckKeyh.h"
#include <math.h>
#include <DxLib.h>
#include "Game.h"

Player::Player(float x, float y, float z, int hp,int mp) :Character(x,y,z,hp,mp)
{
	//3Dモデル読み込み
	PlayerModelHandle = MV1LoadModel("../materials/model/霧雨魔理沙/霧雨魔理沙箒.pmd");
	if (PlayerModelHandle == -1)return;

	MV1SetScale(PlayerModelHandle, VGet(2, 2, 2));

	attachIndex = MV1AttachAnim(PlayerModelHandle, 0);
	totalTime = MV1GetAttachAnimTotalTime(PlayerModelHandle, attachIndex);
	motionNumber = 1;

	/*attachIndex[1] = MV1AttachAnim(PlayerModelHandle, 1, -1, FALSE);
	totalTime[1] = MV1GetAttachAnimTotalTime(PlayerModelHandle, attachIndex[0]);

	attachIndex[2] = MV1AttachAnim(PlayerModelHandle, 2, -1, FALSE);
	totalTime[2] = MV1GetAttachAnimTotalTime(PlayerModelHandle, attachIndex[0]);*/


	PlayerMaterialNum = MV1GetMaterialNum(PlayerModelHandle);
	for (int i = 0; i < PlayerMaterialNum; i++)
	{
		dotWidth = MV1GetMaterialOutLineDotWidth(PlayerModelHandle, i);
		MV1SetMaterialOutLineDotWidth(PlayerModelHandle, i, dotWidth / 10.0f);
	}

	plBullet = new Bullet();

	zLocation = 1;

	return;
}

Player::~Player()
{
	delete plBullet;
}

void Player::Move(Player* player,VECTOR enemyVector,int isShot)
{
	//キー取得  
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (isShot >= 30)
	{
		if (player->vector.y > 30)
		{
			if (key & PAD_INPUT_DOWN) player->vector.y -= 5.0f;
		}
		if (player->vector.y < 200)
		{
			if (key & PAD_INPUT_UP) player->vector.y += 5.0f;
		}
		if (player->vector.x < 300)
		{
			if (key & PAD_INPUT_LEFT) player->vector.x += 5.0f;
		}
		if (player->vector.x > -120)
		{
			if (key & PAD_INPUT_RIGHT) player->vector.x -= 5.0f;
		}
		if (zLocation == 1)
		{
			if (key & PAD_INPUT_5)
			{
				player->vector.z += 50.0f;
				zLocation = 0;
			}
		}
		if (zLocation == 0)
		{
			if (key & PAD_INPUT_8)
			{
				player->vector.z -= 50.0f;
				zLocation = 1;
			}
		}

	}


	theta = atan((player->vector.x - enemyVector.x) / 200.0f);
	phi = atan((player->vector.y - enemyVector.y) / (200.0f / cos(theta)));

	MV1SetRotationXYZ(PlayerModelHandle, VGet(-phi, theta, 0));

	//3Dモデルの移動
	MV1SetPosition(PlayerModelHandle, player->vector);
}


void Player::Draw()
{

	// ３Ｄモデルの描画  
	MV1DrawModel(PlayerModelHandle);

	//プレイヤーHPの描画
	DrawBox(50, 850, 50 + 2 * GetHp(), 900, GetColor(255, 36, 0), TRUE);
	DrawFormatString(50, 900, GetColor(255, 255, 255), "HP");

	//プレイヤーMPの描画
	DrawBox(300, 850, 300 + 2 * GetMp(), 900, GetColor(0, 36, 255), TRUE);
	DrawFormatString(300, 900, GetColor(255, 255, 255), "MP");
}

void Player::MotionHandler(Player* player, VECTOR enemyVector, int isShot)
{
	Move(player, enemyVector, isShot);
	//アニメーションさせたかった

	if (Game::counter%10==0)
	{
		if (GetMp()<100)
		{
			AddMp(1);
		}
	}

	//アニメーションのセット
	MV1SetAttachAnimTime(PlayerModelHandle, attachIndex, totalTime);
}

Bullet* Player::GetBulletObj()
{
	return plBullet;
}