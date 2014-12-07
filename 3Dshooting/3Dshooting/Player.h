#pragma once
#include "Character.h"
#include "BackGround.h"

class Player :
	public Character
{
private:
	int PlayerModelHandle; //���f���f�[�^�̃n���h�����i�[
	int PlayerMaterialNum; //���f���̃}�e���A���f�[�^�i�[
	int key; //�������L�[���
	float dotWidth;
	VECTOR targetMoveDirection; //���f���̕����x�N�g��
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

