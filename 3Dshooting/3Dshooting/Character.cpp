#include "Character.h"
#include "DxLib.h"


Character::Character(float x, float y, float z,float angle, int hp)
{
	this->angle = angle;
	vector = VGet(x, y, z);
}


Character::~Character()
{
}

VECTOR Character::operator+(VECTOR v)
{
	this->vector.x += v.x;
	this->vector.y += v.y;
	this->vector.z += v.z;
	return v;
}

VECTOR Character::operator-(VECTOR v)
{
	this->vector.x -= v.x;
	this->vector.y -= v.y;
	this->vector.z -= v.z;
	return v;
}

//Še—v‘f‚É‘«‚·ŠÖ”
void Character::AddX(float x)
{
	vector.x += x;
}

void Character::AddY(float y)
{
	vector.y += y;
}

void Character::AddZ(float z)
{
	vector.z += z;
}

float Character::GetX()
{
	return vector.x;
}

float Character::GetY()
{
	return vector.y;
}

float Character::GetZ()
{
	return vector.z;
}

VECTOR Character::GetVector()const
{
	return vector;
}