#pragma once
#include "vector3.h"
#include <DxLib.h>

class Character
{
private:
	VECTOR vector;
	int hp;
public:
	Character(float x,float y,float z,int hp);
	~Character();
	virtual void Draw() = 0; //各キャラクタの描画関数
	virtual int GetModelHandle()=0; //各キャラクタのモデルデータハンドル
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
	VECTOR GetVector();
};

