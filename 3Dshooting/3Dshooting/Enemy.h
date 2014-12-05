#pragma once
#include "Character.h"
#include "Vector3.h"

class Enemy :
	public Character
{
private:
	int ModelHandle;
	int key; //‰Ÿ‚µ‚½ƒL[î•ñ
public:
	Enemy(float x, float y, float z,int hp);
	~Enemy();
	void Draw();
	void Control();
};

