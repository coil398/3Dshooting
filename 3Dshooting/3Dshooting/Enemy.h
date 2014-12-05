#pragma once
#include "Character.h"
#include "Vector3.h"

class Enemy :
	public Character
{
public:
	Enemy(float x, float y, float z,int hp);
	~Enemy();
};

