#pragma once
#include "Character.h"
class Player :
	public Character
{
private:
	int PlayerModelHandle; //���f���f�[�^�̃n���h�����i�[
	int PlayerMaterialNum; //���f���̃}�e���A���f�[�^�i�[
	int key; //�������L�[���
	float dotWidth;
public:
	Player(float x,float y,float z,int hp);
	~Player();
	void Draw();
	void Move();
	int GetModelHandle()override;
};

