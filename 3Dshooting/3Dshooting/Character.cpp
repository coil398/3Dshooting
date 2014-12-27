#include "Character.h"
#include "DxLib.h"


Character::Character(float x, float y, float z, int hp)
{
	vector = VGet(x, y, z);
}


Character::~Character()
{
}