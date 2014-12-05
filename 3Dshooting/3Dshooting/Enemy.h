#pragma once
#include "Character.h"
#include "Vector3.h"

class Enemy :
	public Character
{
private:
	int EnemyModelHandle; //���f���f�[�^�̃n���h�����i�[
	int EnemyMaterialNum; //���f���̃}�e���A���f�[�^�i�[
	int key; //�������L�[���
	float dotWidth;
public:
	Enemy(float x, float y, float z,int hp);
	~Enemy();
	void Draw();
	void Move();
	int GetModelHandle()override;
};

