#pragma once
#include <dxlib.h>
#define BULLET 256 //�e�̌��E��

class Player;
class Enemy;
class Character;

//������������C���f�N�T�g�����ق���������������Ȃ��H
class Bullet
{
private:
	int key;
	int bullet[BULLET]; //�e���i�[�i�O�F�����@�P�F�ʏ�e�@�Q�F�z�[�~���O�e�j
	int i, j, k, l;
	int isShot; //�e�����Ă邩�ǂ���
	int isGraze[BULLET]; //�O���C�Y����
	int enFlag;
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
	void Shot(VECTOR start, VECTOR target,Player* character);
	void Shot(VECTOR start, VECTOR target, Enemy* character);
	void Calculator(int i, VECTOR start, VECTOR target);
	void Draw();
	void ShotController(VECTOR start, VECTOR target);
	int IsShot();
	void NormalShot(VECTOR start,VECTOR target,Player* player);
	void NormalShot(VECTOR start, VECTOR target, Enemy* enemy);
	void HomingShot(VECTOR start, VECTOR target, Player* player);
	void HomingShot(VECTOR start, VECTOR target, Enemy* enemy);
	void Collision(Character* character);
};

