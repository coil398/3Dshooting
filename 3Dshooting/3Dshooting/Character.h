#pragma once
#include <DxLib.h>
#include "Bullet.h"

class Character
{
private:
	VECTOR direction; //モデルの向く方向
	VECTOR UpMoveVec; // 方向ボタン「↑」を入力をしたときのプレイヤーの移動方向ベクトル
	VECTOR LeftMoveVec; // 方向ボタン「←」を入力をしたときのプレイヤーの移動方向ベクトル
	VECTOR MoveVec; // このフレームの移動ベクトル
	int MoveFlag; // 移動したかどうかのフラグ( 1:移動した  0:移動していない )
	int hp,mp;
	float angle; //モデルの向いている方向
	int isDamaged; //弾が当たったかのフラグ
	
protected:
	float theta; //モデルのy軸回転角
	float phi; //モデルのx軸回転角
	int animIndex; //アニメーションデータ
	int attachIndex; //モーションデータ
	float totalTime; //再生時間
	int motionNumber; //再生しているモーションの番号
	float motiontime;
	float colorCode;
	VECTOR colVector; //当たり判定用のベクトル
public:
	Character(float x,float y,float z,int hp,int mp);
	~Character();
	int GetHp()const;
	void AddHp(int hp);
	int GetMp()const;
	void AddMp(int mp);
	VECTOR vector; //モデルの座標
	virtual void Draw() = 0;
	virtual Bullet* GetBulletObj() = 0;
};

