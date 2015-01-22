#pragma once
#include <DxLib.h>
#include "Bullet.h"

class Character
{
private:
	VECTOR direction; //���f���̌�������
	VECTOR UpMoveVec; // �����{�^���u���v����͂������Ƃ��̃v���C���[�̈ړ������x�N�g��
	VECTOR LeftMoveVec; // �����{�^���u���v����͂������Ƃ��̃v���C���[�̈ړ������x�N�g��
	VECTOR MoveVec; // ���̃t���[���̈ړ��x�N�g��
	int MoveFlag; // �ړ��������ǂ����̃t���O( 1:�ړ�����  0:�ړ����Ă��Ȃ� )
	
	float angle; //���f���̌����Ă������
	int isDamaged; //�e�������������̃t���O
	
protected:
	int hp, mp;
	float theta; //���f����y����]�p
	float phi; //���f����x����]�p
	int animIndex; //�A�j���[�V�����f�[�^
	int attachIndex; //���[�V�����f�[�^
	float totalTime; //�Đ�����
	int motionNumber; //�Đ����Ă��郂�[�V�����̔ԍ�
	float motiontime;
	float colorCode;
	VECTOR colVector; //�����蔻��p�̃x�N�g��
public:
	Character(float x,float y,float z,int hp,int mp);
	~Character();
	int GetHp()const;
	void AddHp(int hp);
	int GetMp()const;
	void AddMp(int mp);
	VECTOR vector; //���f���̍��W
	virtual void Draw() = 0;
	virtual Bullet* GetBulletObj() = 0;
};

