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
	void Draw();//�X�e�[�W�̕`��
	int GetModelHandle();
};

