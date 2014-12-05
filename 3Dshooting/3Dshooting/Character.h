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

	//VECTOR型用の演算子オーバーロード
	void AddVector(float );
};

