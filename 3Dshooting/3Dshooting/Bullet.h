#pragma once
#include <dxlib.h>
#define BULLET 100 //�e�̌��E��


//������������C���f�N�T�g�����ق���������������Ȃ��H
class Bullet
{
private:
	int key;
	int bullet[BULLET];
	int i, j,k;
	int isShot; //�e�����Ă邩�ǂ���
	//�o���b�g�̑���
	float bulletSpeed;
	VECTOR direction[BULLET];
	VECTOR xAxis; //x�������x�N�g��
	VECTOR yAxis; //y�������x�N�g��
	VECTOR Move[BULLET]; //�e�̍��W�ɑ����Ă����x�N�g��
	VECTOR bulletLocation[BULLET]; //�e�̈ʒu
public:
	int bulletImage[5];
	Bullet();
	~Bullet();
	void Shot(VECTOR start, VECTOR target);
	void Calculator(int i, VECTOR start, VECTOR target);
	void Draw();
	void ShotController(VECTOR start, VECTOR target);
};

