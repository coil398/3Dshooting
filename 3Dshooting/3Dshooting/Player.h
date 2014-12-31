#pragma once
#include "Character.h"
#include "Bullet.h"

class Player:public Character
{
private:
	int PlayerModelHandle; //���f���f�[�^�̃n���h�����i�[
	int PlayerMaterialNum; //���f���̃}�e���A���f�[�^�i�[
	float x, y, z;
	float dotWidth;
	int i; //�f�o�b�O�p
	Bullet* plBullet;
public:
	Player(float x,float y,float z,int hp,int mp);
	void Move(Player* player,VECTOR enemyVector,int isShot);
	void Draw()override;
	void MotionHandler(Player* player, VECTOR enemyVector, int isShot);
	Bullet* GetBulletObj()override;
	~Player();
};