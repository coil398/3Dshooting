#pragma once
#include "Character.h"
#include "Bullet.h"

class Player:public Character
{
private:
	int PlayerModelHandle; //モデルデータのハンドルを格納
	int PlayerMaterialNum; //モデルのマテリアルデータ格納
	float x, y, z;
	float dotWidth;
	int i; //デバッグ用
	Bullet* plBullet;
	int zLocation;
public:
	Player(float x,float y,float z,int hp,int mp);
	void Move(Player* player,VECTOR enemyVector,int isShot);
	void Draw()override;
	void MotionHandler(Player* player, VECTOR enemyVector, int isShot);
	Bullet* GetBulletObj()override;
	~Player();
};