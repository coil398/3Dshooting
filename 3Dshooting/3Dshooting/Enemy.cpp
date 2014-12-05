#include "Enemy.h"
#include <DxLib.h>
#include "CheckKeyh.h"

Enemy::Enemy(float x, float y, float z,int hp) :Character(x, y, z,hp)
{
	
}


Enemy::~Enemy()
{
}

void Enemy::Move()
{
	key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (key & PAD_INPUT_DOWN) vector.y -= 1.0f;
	if (key & PAD_INPUT_UP) vector.y += 1.0f;
	if (key & PAD_INPUT_LEFT) x -= 1.0f;
	if (key & PAD_INPUT_RIGHT) x += 1.0f;
	if (CheckKey::Key[KEY_INPUT_Z] >= 1) z+=1.0f;
	if (CheckKey::Key[KEY_INPUT_X] >= 1) z-=1.0f;
}

void Enemy::Draw()
{
	//3Dƒ‚ƒfƒ‹‚ÌˆÚ“®
	MV1SetPosition(GetModelHandle(), VGet(x, y, z));
	//3Dƒ‚ƒfƒ‹‚Ì•`‰æ
	MV1DrawModel(GetModelHandle());
}

int Enemy::GetModelHandle()
{
	return EnemyModelHandle;
}
