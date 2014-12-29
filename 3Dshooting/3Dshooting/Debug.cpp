#include "Debug.h"
#include <DxLib.h>

Debug::Debug()
{
	mStartTime = 0;
	mCount = 0;
	mFps = 0;
}

Debug::~Debug()
{
}

bool Debug::Update(){
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

float Debug::GetFps()
{
	return mFps;
}

void Debug::Draw(const Player& player,const Enemy& enemy){
	/*sprintf_s(locx, "%f.3", x);
	sprintf_s(locy, "%f.3", y);
	sprintf_s(locz, "%f.3", z);*/
	DrawFormatString(0, 0, GetColor(255, 255, 255), "FPS : %.1f", mFps);
	DrawFormatString(0, 20, GetColor(255, 255, 255), "PLAYER:x = %f",player.vector.x);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "PLAYER:y = %f",player.vector.y);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "PLAYER:z = %f",player.vector.z);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "ENEMY:x = %f", enemy.vector.x);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "ENEMY:y = %f", enemy.vector.y);
	DrawFormatString(0, 120, GetColor(255, 255, 255), "ENEMY:z = %f", enemy.vector.z);
	DrawFormatString(0, 140, GetColor(255, 255, 255), "PLAYER:HP = %d", player.GetHp());
	DrawFormatString(0, 160, GetColor(255, 255, 255), "PLAYER:MP = %d", player.GetMp());
	DrawFormatString(0, 180, GetColor(255, 255, 255), "ENEMY:HP = %d", enemy.GetHp());
	DrawFormatString(0, 200, GetColor(255, 255, 255), "ENEMY:MP = %d", enemy.GetMp());
}

void Debug::Wait(){
	int tookTime = GetNowCount() - mStartTime;	//������������
	int waitTime = mCount * 1000 / FPS - tookTime;	//�҂ׂ�����
	if (waitTime > 0){
		Sleep(waitTime);	//�ҋ@
	}
}