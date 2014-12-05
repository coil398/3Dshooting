#pragma once
#include "vector3.h"

class Character
{
private:
	int hp;
	Vector3* vector3;
public:
	Character(float x,float y,float z,int hp);
	~Character();
};

