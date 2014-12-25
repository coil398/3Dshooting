#pragma once
#include "Character.h"

class Player:public Character
{
private:
	int PlayerModelHandle; //モデルデータのハンドルを格納
	int AttachIndex; //モーションデータ
	int PlayerMaterialNum; //モデルのマテリアルデータ格納
	float x, y, z;
	int hp;
	float dotWidth;
	float time;
public:
	Player(float x,float y,float z,int hp);
	void Move(Player* player,VECTOR enemyVector);
	void Draw(VECTOR pos)override;
	~Player();
};