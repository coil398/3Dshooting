#pragma once
#include <dxlib.h>
#define BULLET 100 //弾の限界数


//もしかしたらインデクサ使ったほうがいいかもしれない？
class Bullet
{
private:
	int key;
	int bullet[BULLET];
	int i, j,k;
	int isShot; //弾が撃てるかどうか
	//バレットの速さ
	float bulletSpeed;
	VECTOR direction[BULLET];
	VECTOR xAxis; //x軸方向ベクトル
	VECTOR yAxis; //y軸方向ベクトル
	VECTOR Move[BULLET]; //弾の座標に足していくベクトル
	VECTOR bulletLocation[BULLET]; //弾の位置
public:
	int bulletImage[5];
	Bullet();
	~Bullet();
	void Shot(VECTOR start, VECTOR target);
	void Calculator(int i, VECTOR start, VECTOR target);
	void Draw();
	void ShotController(VECTOR start, VECTOR target);
	int IsShot();
};

