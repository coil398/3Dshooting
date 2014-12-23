#include "Player.h"
#include "Character.h"
#include "CheckKeyh.h"
#include <math.h>

Player::Player(float x, float y, float z, int hp) :Character(x,y,z,hp)
{
	//3D���f���ǂݍ���
	PlayerModelHandle = MV1LoadModel("../materials/model/marisa/marisa_1.04NS.pmx");
	if (PlayerModelHandle == -1)return;

	PlayerMaterialNum = MV1GetMaterialNum(PlayerModelHandle);
	for (int i = 0; i < PlayerMaterialNum; i++)
	{
		dotWidth = MV1GetMaterialOutLineDotWidth(PlayerModelHandle, i);
		MV1SetMaterialOutLineDotWidth(PlayerModelHandle, i, dotWidth / 5.0f);
	}
	return;
}

Player::~Player()
{
	
}

void Player::Move(Player* player,VECTOR enemyVector)
{
	//�L�[�擾  
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

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


	theta = atan((player->vector.x - enemyVector.x) / 200.0f);
	phi = atan((player->vector.y - enemyVector.y) / (200.0f / cos(theta)));

	MV1SetRotationXYZ(PlayerModelHandle, VGet(-phi, theta, 0));
}


void Player::Draw(VECTOR pos)
{
	//3D���f���̈ړ�
	MV1SetPosition(PlayerModelHandle, pos);
	// �R�c���f���̕`��  
	MV1DrawModel(PlayerModelHandle);
}