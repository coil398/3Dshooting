#include "Player.h"
#include "DXlib.h"
#include "CheckKeyh.h"


Player::Player(float x, float y, float z,float angle,int hp) :Character(x,y,z,angle,hp)
{
	//3D���f���ǂݍ���
	PlayerModelHandle = MV1LoadModel("../materials/model/marisa/marisa.pmx");
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

void Player::Move()
{
	key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

<<<<<<< HEAD
	if (key & PAD_INPUT_DOWN) AddZ(-1.0f);
	if (key & PAD_INPUT_UP) AddZ(1.0f);
	if (key & PAD_INPUT_LEFT) AddX(-1.0f);
=======
	if (key & PAD_INPUT_DOWN) AddZ(-1.0f); //���s��
	if (key & PAD_INPUT_UP) AddZ(1.0f);
	if (key & PAD_INPUT_LEFT) AddX(-1.0f); //���E
>>>>>>> origin/master
	if (key & PAD_INPUT_RIGHT) AddX(1.0f);
	//if (CheckKey::Key[KEY_INPUT_Z] >= 1) AddZ(1.0f);
	//if (CheckKey::Key[KEY_INPUT_X] >= 1) AddZ(-1.0f);
}

void Player::Rot()
{
	//���ɂȂ�
}

void Player::Draw()
{
	//3D���f���̈ړ�
	MV1SetPosition(GetModelHandle(), VGet(GetX(), GetY(), GetZ()));
	//3D���f���̕`��
	MV1DrawModel(GetModelHandle());
}

int Player::GetModelHandle()
{
	return PlayerModelHandle;
}
