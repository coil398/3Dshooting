#pragma once
#include <dxlib.h>
<<<<<<< HEAD
#include "Player.h"
#include "Enemy.h"
=======
#include "Character.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include <math.h>
>>>>>>> origin/master
#define BULLET 100 //弾の限界数

//もしかしたらインデクサ使ったほうがいいかもしれない？
class Bullet
{
private:
	int key;
	int bullet[BULLET];
	int i, j, k, l;
	int isShot; //弾が撃てるかどうか
<<<<<<< HEAD
<<<<<<< HEAD
	int isGraze[BULLET]; //グレイズ判定
	int isCol[BULLET]; //コリジョン判定
=======
	int isGraze; //グレイズ判定
>>>>>>> origin/菫ｮ豁｣
	//バレットの速さ
	float bulletSpeed;
	float distVector; //ベクトルのノルム(２乗で使用)
=======
	int isGraze[BULLET]; //グレイズ判定
	//バレットの速さ
	float bulletSpeed;
	float distVector; //ベクトルの距離(２乗)
>>>>>>> origin/master
	VECTOR direction[BULLET];
	VECTOR xAxis; //x軸方向ベクトル
	VECTOR yAxis; //y軸方向ベクトル
	VECTOR move[BULLET]; //弾の座標に足していくベクトル
	VECTOR bulletLocation[BULLET]; //弾の位置
	VECTOR colVector; //コリジョン判定のためのベクトル
public:
	int bulletImage[5];
	Bullet();
	~Bullet();
	void Shot(VECTOR start, VECTOR target);
	void Calculator(int i, VECTOR start, VECTOR target);
	void Draw();
	void ShotController(VECTOR start, VECTOR target);
	//void Collision(Player* player); //コリジョン判定
	//void Collision(Enemy* enemy); //コリジョン判定
	int IsShot();
	void Collision(Player* player);
	//void Collision(Enemy* enemy);
};

