#pragma once
#include "Character.h"
#include "Vector3.h"

class Enemy :
	public Character
{
private:
	int ModelHandle;
	int key; //押したキー情報
public:
	Enemy(float x, float y, float z,int hp);
	~Enemy();
	void Draw();
	void Control();
};

