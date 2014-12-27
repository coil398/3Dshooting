#pragma once
#include "Character.h"

class Enemy :
	public Character
{
private:
	int EnemyModelHandle; //���f���f�[�^�̃n���h�����i�[
	int EnemyMaterialNum; //���f���̃}�e���A���f�[�^�i�[
	int key; //�������L�[���
	float dotWidth;
	float time;
public:
	Enemy(float x, float y, float z,int hp);
	~Enemy();
	void Draw(VECTOR pos)override;
	void Move(VECTOR playerVector,Enemy* enemy);
	//int GetModelHandle()override;
};

