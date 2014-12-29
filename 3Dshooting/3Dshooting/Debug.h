#pragma once
#include "Player.h"
#include "Enemy.h"

class Debug{
	int mStartTime;         //����J�n����
	int mCount;             //�J�E���^
	float mFps;             //fps
	static const int N = 60;//���ς����T���v����
	static const int FPS = 60;	//�ݒ肵��FPS
	int isDebug; //�f�o�b�O���
public:
	Debug();
	~Debug();

	bool Update();
	float GetFps();
	void Draw(const Player& player,const Enemy& enemy);

	void Wait();
};