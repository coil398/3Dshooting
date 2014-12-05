#include "Enemy.h"
#include <DxLib.h>
#include "CheckKeyh.h"

Enemy::Enemy(float x, float y, float z,int hp) :Character(x, y, z,hp)
{
	//3Dƒ‚ƒfƒ‹“Ç‚Ýž‚Ý
	ModelHandle = MV1LoadModel("../materials/model/marisa/marisa_1.04NS.pmx");
}


Enemy::~Enemy()
{
}

void Enemy::Draw()
{
	//3Dƒ‚ƒfƒ‹‚ÌˆÚ“®
	MV1SetPosition(ModelHandle, VGet(x, y, z));
	//3Dƒ‚ƒfƒ‹‚Ì•`‰æ
	MV1DrawModel(ModelHandle);
}

void Enemy::Control()
{
	key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (key & PAD_INPUT_DOWN) y -= 1.0f;
	if (key & PAD_INPUT_UP) y += 1.0f;
	if (key & PAD_INPUT_LEFT) x -= 1.0f;
	if (key & PAD_INPUT_RIGHT) x += 1.0f;
	if (CheckKey::Key[KEY_INPUT_Z] >= 1) z+=1.0f;
	if (CheckKey::Key[KEY_INPUT_X] >= 1) z-=1.0f;
}
