#pragma once
#include <DxLib.h>

class Character
{
private:
	VECTOR vector; //モデルの座標
	VECTOR direction; //モデルの向く方向
	VECTOR UpMoveVec; // 方向ボタン「↑」を入力をしたときのプレイヤーの移動方向ベクトル
	VECTOR LeftMoveVec; // 方向ボタン「←」を入力をしたときのプレイヤーの移動方向ベクトル
	VECTOR MoveVec; // このフレームの移動ベクトル
	int MoveFlag; // 移動したかどうかのフラグ( 1:移動した  0:移動していない )
	int hp;
	float angle; //モデルの向いている方向
public:
	Character(float x,float y,float z,float angle,int hp);
	~Character();
	virtual void Draw() = 0; //各キャラクタの描画関数
	virtual int GetModelHandle()=0; //各キャラクタのモデルデータハンドル
	virtual void SetModelHandle(int ModelHandle) = 0;
	virtual void Move() = 0; //キャラクター移動関数
	virtual void Rot() = 0; //キャラクター回転関数

	//VECTOR型用の演算子オーバーロード
	VECTOR operator+(VECTOR v);
	VECTOR operator-(VECTOR v);
	void AddX(float x);
	void AddY(float y);
	void AddZ(float z);
	float GetX();
	float GetY();
	float GetZ();
	VECTOR GetVector()const;
	float GetAngle();
	void SetVector(VECTOR v);
	void SetAngle(float angle);
};

