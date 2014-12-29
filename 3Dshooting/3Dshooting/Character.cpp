#include "Character.h"
#include "DxLib.h"


Character::Character(float x, float y, float z, int hp, int mp)
{
	vector = VGet(x, y, z);
	this->hp = hp;
	this->mp = mp;
}


Character::~Character()
{

}

int Character::GetHp()const
{
	return hp;
}

void Character::AddHp(int hp)
{
	this->hp += hp;
}

int Character::GetMp()const
{
	return mp;
}

void Character::AddMp(int mp)
{
	this->mp += mp;
}