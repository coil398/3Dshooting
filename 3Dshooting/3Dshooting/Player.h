#pragma once
#include "Character.h"

class Player:public Character
{
private:
	int PlayerModelHandle; //���f���f�[�^�̃n���h�����i�[
	int AttachIndex; //���[�V�����f�[�^
	int PlayerMaterialNum; //���f���̃}�e���A���f�[�^�i�[
	float x, y, z;
	int hp;
	float dotWidth;
	float time;
public:
	Player(float x,float y,float z,int hp);
	void Move(Player* player,VECTOR enemyVector);
	void Draw(VECTOR pos)override;
	~Player();
};