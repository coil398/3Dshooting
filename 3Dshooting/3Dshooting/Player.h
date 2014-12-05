#pragma once
#include "Character.h"
class Player :
	public Character
{
private:
	int PlayerModelHandle; //モデルデータのハンドルを格納
	int PlayerMaterialNum; //モデルのマテリアルデータ格納
	int key; //押したキー情報
	float dotWidth;
public:
	Player(float x,float y,float z,int hp);
	~Player();
	void Draw();
	void Move();
	int GetModelHandle()override;
};

