#pragma once
#include <dxlib.h>
#define BULLET 256 //弾の限界数

class Player;
class Enemy;
class Character;

//もしかしたらインデクサ使ったほうがいいかもしれない？
class Bullet
{
private:
	int key;
	int bullet[BULLET]; //弾を格納（０：未発　１：通常弾　２：ホーミング弾）
	int i, j, k, l;
	int isShot; //弾が撃てるかどうか
	int isGraze[BULLET]; //グレイズ判定
	int enFlag;
	//バレットの速さ
	float bulletSpeed;
	float distVector; //ベクトルのノルム(２乗で使用)
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
	void Shot(VECTOR start, VECTOR target,Player* character);
	void Shot(VECTOR start, VECTOR target, Enemy* character,int randNumber);
	void Calculator(int i, VECTOR start, VECTOR target);
	void Draw();
	void ShotController(VECTOR start, VECTOR target);
	int IsShot();
	void NormalShot(VECTOR start,VECTOR target,Player* player);
	void NormalShot(VECTOR start, VECTOR target, Enemy* enemy);
	void HomingShot(VECTOR start, VECTOR target, Player* player);
	void HomingShot(VECTOR start, VECTOR target, Enemy* enemy);
	void SuperShot(VECTOR start, VECTOR target, Player* player);
	void SuperShot(VECTOR start, VECTOR target, Enemy* enemy);
	void Collision(Character* character);
};

