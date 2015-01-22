#pragma once
#include "Character.h"
#include "Bullet.h"

class Enemy :public Character
{
private:
	int EnemyModelHandle; //モデルデータのハンドルを格納
	int EnemyMaterialNum; //モデルのマテリアルデータ格納
	int key; //押したキー情報
	float dotWidth;
	int hpGaugeHandle;
	float hpRatio;
	Bullet* enBullet;
	int randNumber;
	int moveFlag;
	int moveNumber;
public:
	Enemy(float x, float y, float z,int hp,int mp);
	~Enemy();
	void Draw()override;
	void MotionHandler(VECTOR playerVector, Enemy* enemy, int isShot);
	void Move(VECTOR playerVector, Enemy* enemy, int isShot);
	//int GetModelHandle()override;
	Bullet* GetBulletObj()override;
	void Random();
	int GetRandom();
};

