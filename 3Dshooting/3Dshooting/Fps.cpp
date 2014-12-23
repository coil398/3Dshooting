#include "Fps.h"
#include <DxLib.h>


Fps::Fps()
{
	mStartTime = 0;
	mCount = 0;
	mFps = 0;
}

Fps::~Fps()
{
}

bool Fps::Update(){
	if (mCount == 0){ //1�t���[���ڂȂ玞�����L��
		mStartTime = GetNowCount();
	}
	if (mCount == N){ //60�t���[���ڂȂ畽�ς��v�Z����
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)N);
		mCount = 0;
		mStartTime = t;
	}
	mCount++;
	return true;
}

float Fps::GetFps()
{
	return mFps;
}

void Fps::Draw(float x,float y){
	char locx[100];
	char locy[100];
	sprintf_s(locx, "%f.3", x);
	sprintf_s(locy, "%f.3", y);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", mFps);
	DrawFormatString(0, 20, GetColor(255, 255, 255), locx);
	DrawFormatString(0, 40, GetColor(255, 255, 255), locy);
}

void Fps::Wait(){
	int tookTime = GetNowCount() - mStartTime;	//������������
	int waitTime = mCount * 1000 / FPS - tookTime;	//�҂ׂ�����
	if (waitTime > 0){
		Sleep(waitTime);	//�ҋ@
	}
}