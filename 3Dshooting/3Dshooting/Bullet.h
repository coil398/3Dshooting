#pragma once
#include <dxlib.h>
<<<<<<< HEAD
#include "Player.h"
#include "Enemy.h"
=======
#include "Character.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include <math.h>
>>>>>>> origin/master
#define BULLET 100 //�e�̌��E��

//������������C���f�N�T�g�����ق���������������Ȃ��H
class Bullet
{
private:
	int key;
	int bullet[BULLET];
	int i, j, k, l;
	int isShot; //�e�����Ă邩�ǂ���
<<<<<<< HEAD
<<<<<<< HEAD
	int isGraze[BULLET]; //�O���C�Y����
	int isCol[BULLET]; //�R���W��������
=======
	int isGraze; //�O���C�Y����
>>>>>>> origin/修正
	//�o���b�g�̑���
	float bulletSpeed;
	float distVector; //�x�N�g���̃m����(�Q��Ŏg�p)
=======
	int isGraze[BULLET]; //�O���C�Y����
	//�o���b�g�̑���
	float bulletSpeed;
	float distVector; //�x�N�g���̋���(�Q��)
>>>>>>> origin/master
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
	void Collision(Player* player);
	//void Collision(Enemy* enemy);
};

