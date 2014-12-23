#pragma once

class Fps{
	int mStartTime;         //測定開始時刻
	int mCount;             //カウンタ
	float mFps;             //fps
	static const int N = 60;//平均を取るサンプル数
	static const int FPS = 60;	//設定したFPS

public:
	Fps();
	~Fps();

	bool Update();
	float GetFps();
	void Draw(float x,float y);

	void Wait();
};