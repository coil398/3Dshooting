#pragma once
#include <DxLib.h>

class Character
{
private:
	VECTOR vector; //���f���̍��W
	VECTOR direction; //���f���̌�������
	VECTOR UpMoveVec; // �����{�^���u���v����͂������Ƃ��̃v���C���[�̈ړ������x�N�g��
	VECTOR LeftMoveVec; // �����{�^���u���v����͂������Ƃ��̃v���C���[�̈ړ������x�N�g��
	VECTOR MoveVec; // ���̃t���[���̈ړ��x�N�g��
	int MoveFlag; // �ړ��������ǂ����̃t���O( 1:�ړ�����  0:�ړ����Ă��Ȃ� )
	int hp;
	float angle; //���f���̌����Ă������
public:
	Character(float x,float y,float z,float angle,int hp);
	~Character();
	virtual void Draw() = 0; //�e�L�����N�^�̕`��֐�
	virtual int GetModelHandle()=0; //�e�L�����N�^�̃��f���f�[�^�n���h��
	virtual void Move() = 0; //�L�����N�^�[�ړ��֐�
	virtual void Rot() = 0; //�L�����N�^�[��]�֐�

	//VECTOR�^�p�̉��Z�q�I�[�o�[���[�h
	VECTOR operator+(VECTOR v);
	VECTOR operator-(VECTOR v);
	void AddX(float x);
	void AddY(float y);
	void AddZ(float z);
	float GetX();
	float GetY();
	float GetZ();
	VECTOR GetVector()const;
};

