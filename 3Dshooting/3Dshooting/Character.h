#pragma once
#include <DxLib.h>

class Character
{
private:
	VECTOR direction; //モデルの向く方向
	VECTOR UpMoveVec; // 方向ボタン「↑」を入力をしたときのプレイヤーの移動方向ベクトル
	VECTOR LeftMoveVec; // 方向ボタン「←」を入力をしたときのプレイヤーの移動方向ベクトル
	VECTOR MoveVec; // このフレームの移動ベクトル
	int MoveFlag; // 移動したかどうかのフラグ( 1:移動した  0:移動していない )
	int hp;
	float angle; //モデルの向いている方向
	int isDamaged; //弾が当たったかのフラグ
protected:
	float theta; //モデルのy軸回転角
	float phi; //モデルのx軸回転角
	int AttachIndex; //モーションデータ
	int TotalTime; //再生時間
public:
	Character(float x,float y,float z,int hp);
	~Character();

	VECTOR vector; //モデルの座標
	virtual void Draw(VECTOR pos) = 0;
};

