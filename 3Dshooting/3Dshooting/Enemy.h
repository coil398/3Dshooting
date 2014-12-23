#pragma once
#include "Character.h"

class Enemy :
	public Character
{
private:
	int EnemyModelHandle; //モデルデータのハンドルを格納
	int EnemyMaterialNum; //モデルのマテリアルデータ格納
	int key; //押したキー情報
	float dotWidth;
public:
	Enemy(float x, float y, float z,int hp);
	~Enemy();
	void Draw(VECTOR pos)override;
	void Move(VECTOR playerVector,Enemy* enemy);
	//int GetModelHandle()override;
};

