#include "Character.h"
#include "Vector3.h"


Character::Character(float x,float y,float z,int hp)
{
	this->hp = hp;
	vector3->SetVector3(x, y, z);
}


Character::~Character()
{
}