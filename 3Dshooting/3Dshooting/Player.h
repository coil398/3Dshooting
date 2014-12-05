#pragma once
#include "Character.h"
class Player :
	public Character
{
public:
	Player(float x,float y,float z,int hp);
	~Player();
};

