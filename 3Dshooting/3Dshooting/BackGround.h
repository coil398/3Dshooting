#pragma once
#include <DxLib.h>

class BackGround
{
private:
	VECTOR vector;
	int StageModelHandle;
public:
	BackGround();
	~BackGround();
	void Draw();//ステージの描画
	int GetModelHandle();
};

