#pragma once
#include <dxlib.h>
#include "Player.h"
#include "Enemy.h"
#include "Character.h"
#include "Bullet.h"
#include <math.h>
#define BULLET 100 //�e�̌��E��

//������������C���f�N�T�g�����ق���������������Ȃ��H
class Bullet
{
private:
	int key;
	int bullet[BULLET];
	int i, j, k, l;
	int isShot; //�e�����Ă邩�ǂ���
	int isGraze[BULLET]; //�O���C�Y����
	int isCol[BULLET]; //�R���W��������
	//�o���b�g�̑���
	float bulletSpeed;
	float distVector; //�x�N�g���̃m����(�Q��Ŏg�p)
	VECTOR direction[BULLET];
	VECTOR xAxis; //x�������x�N�g��
	VECTOR yAxis; //y�������x�N�g��
	VECTOR move[BULLET]; //�e�̍��W�ɑ����Ă����x�N�g��
	VECTOR bulletLocation[BULLET]; //�e�̈ʒu
	VECTOR colVector; //�R���W��������̂��߂̃x�N�g��
public:
	int bulletImage[5];
	Bullet();
	~Bullet();
	void Shot(VECTOR start, VECTOR target);
	void Calculator(int i, VECTOR start, VECTOR target);
	void Draw();
	void ShotController(VECTOR start, VECTOR target);
	int IsShot();
	void Collision(Player* player);
	void Collision(Enemy* enemy);
};

