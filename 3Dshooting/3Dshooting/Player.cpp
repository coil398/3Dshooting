#include "Player.h"
#include "DXlib.h"
#include "CheckKeyh.h"


Player::Player(float x, float y, float z,int hp) :Character(x,y,z,hp)
{
	//3Dƒ‚ƒfƒ‹“Ç‚İ‚İ
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

	if (key & PAD_INPUT_DOWN) vector.y -= 1.0f;
	if (key & PAD_INPUT_UP) y += 1.0f;
	if (key & PAD_INPUT_LEFT) x -= 1.0f;
	if (key & PAD_INPUT_RIGHT) x += 1.0f;
	if (CheckKey::Key[KEY_INPUT_Z] >= 1) z += 1.0f;
	if (CheckKey::Key[KEY_INPUT_X] >= 1) z -= 1.0f;
}

void Player::Draw()
{
	//3Dƒ‚ƒfƒ‹‚ÌˆÚ“®
	MV1SetPosition(GetModelHandle(), VGet(x, y, z));
	//3Dƒ‚ƒfƒ‹‚Ì•`‰æ
	MV1DrawModel(GetModelHandle());
}

int Player::GetModelHandle()
{
	return PlayerModelHandle;
}
