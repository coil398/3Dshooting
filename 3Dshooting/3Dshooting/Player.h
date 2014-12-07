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
	float r = 0;//�����ɉ�
public:
	Player(float x,float y,float z,float angle,int hp);
	~Player();
	void Draw()override;
	void Move()override;
	void Rot()override;
	int GetModelHandle()override;
};

