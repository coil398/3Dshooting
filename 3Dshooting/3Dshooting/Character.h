#pragma once
#include "vector3.h"
#include <DxLib.h>

class Character
{
private:
	VECTOR vector;
	int hp;
public:
	Character(float x,float y,float z,int hp);
	~Character();
	virtual void Draw() = 0; //�e�L�����N�^�̕`��֐�
	virtual int GetModelHandle()=0; //�e�L�����N�^�̃��f���f�[�^�n���h��

	//VECTOR�^�p�̉��Z�q�I�[�o�[���[�h
	void AddVector(float );
};

