#include "Character.h"
#include "Vector3.h"
#include "DxLib.h"


Character::Character(float x, float y, float z, int hp) :Vector3(x,y,z)
{
	this->hp = hp;
}


Character::~Character()
{
}

void Character::AddVector(float x,float y,float z)
{
	SetVector3(this->x + x, this->y + y, this->z + z);
}