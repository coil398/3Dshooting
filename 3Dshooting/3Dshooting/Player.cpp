#include "Player.h"
#include "DXlib.h"
#include "CheckKeyh.h"


Player::Player(float x, float y, float z,float angle,int hp) :Character(x,y,z,angle,hp)
{
	//3Dモデル読み込み
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
	MV1DeleteModel(PlayerModelHandle);
}

void Player::Move()
{

}

void Player::Rot()
{
	//特になし
}

void Player::Draw()
{
	//3Dモデルの移動
	MV1SetPosition(GetModelHandle(), VGet(GetX(), GetY(), GetZ()));
	//3Dモデルの描画
	MV1DrawModel(GetModelHandle());
}

int Player::GetModelHandle()
{
	return PlayerModelHandle;
}
