#pragma once
#include "Player.h"
#include "Enemy.h"

class Debug{
	int mStartTime;         //測定開始時刻
	int mCount;             //カウンタ
	float mFps;             //fps
	static const int N = 60;//平均を取るサンプル数
	static const int FPS = 60;	//設定したFPS
	int isDebug; //デバッグ情報
public:
	Debug();
	~Debug();

	bool Update();
	float GetFps();
	void Draw(const Player& player,const Enemy& enemy);

	void Wait();
};