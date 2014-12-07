#pragma once
#include "Character.h"
#include "BackGround.h"

class Player :
	public Character
{
private:
	int PlayerModelHandle; //モデルデータのハンドルを格納
	int PlayerMaterialNum; //モデルのマテリアルデータ格納
	int key; //押したキー情報
	float dotWidth;
	VECTOR targetMoveDirection; //モデルの方向ベクトル
public:
	Player(float x,float y,float z,float angle,int hp);
	~Player();
	void Draw()override;
	void Move()override;
	void Rot()override;
	int GetModelHandle()override;
	void SetModelHandle(int ModelHandle)override;
	void Process(int* nowInput, int* edgeInput, Player* player, VECTOR eye, BackGround* stage);
	void PlayerAngle();
	void PlayerMove(Player* player, VECTOR MoveVec);
	void PlayerAnimation(Player*player);
	VECTOR GetTargetMoveDirection();
};

