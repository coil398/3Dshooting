#pragma once

class Fps{
	int mStartTime;         //����J�n����
	int mCount;             //�J�E���^
	float mFps;             //fps
	static const int N = 60;//���ς����T���v����
	static const int FPS = 60;	//�ݒ肵��FPS

public:
	Fps();
	~Fps();

	bool Update();
	float GetFps();
	void Draw();

	void Wait();
};