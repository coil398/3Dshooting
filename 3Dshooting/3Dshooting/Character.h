#pragma once
#include "vector3.h"

class Character:public Vector3
{
private:
	int hp;
public:
	Character(float x,float y,float z,int hp);
	~Character();
	void AddVector(float x, float y, float z);
};

