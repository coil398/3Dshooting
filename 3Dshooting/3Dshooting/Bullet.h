#pragma once
#include <dxlib.h>
#include "Character.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
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
	//�o���b�g�̑���
	float bulletSpeed;
	float distVector; //�x�N�g���̋���(�Q��)
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
	//void Collision(Player* player); //�R���W��������
	//void Collision(Enemy* enemy); //�R���W��������
	int IsShot();
};

