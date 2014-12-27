#pragma once
#include <DxLib.h>

class Character
{
private:
	VECTOR direction; //���f���̌�������
	VECTOR UpMoveVec; // �����{�^���u���v����͂������Ƃ��̃v���C���[�̈ړ������x�N�g��
	VECTOR LeftMoveVec; // �����{�^���u���v����͂������Ƃ��̃v���C���[�̈ړ������x�N�g��
	VECTOR MoveVec; // ���̃t���[���̈ړ��x�N�g��
	int MoveFlag; // �ړ��������ǂ����̃t���O( 1:�ړ�����  0:�ړ����Ă��Ȃ� )
	int hp;
	float angle; //���f���̌����Ă������
	int isDamaged; //�e�������������̃t���O
protected:
	float theta; //���f����y����]�p
	float phi; //���f����x����]�p
	int AttachIndex; //���[�V�����f�[�^
	int TotalTime; //�Đ�����
public:
	Character(float x,float y,float z,int hp);
	~Character();

	VECTOR vector; //���f���̍��W
	virtual void Draw(VECTOR pos) = 0;
};

