#include "Camera.h"
#include <DxLib.h>
#define PI 3.1415926
#include "CheckKeyh.h"
#include <math.h>


Camera::Camera(VECTOR Eye)
{

	model = Eye; //���f���̍��W���擾
	model.y -= -75.0f; //���f���̒��S�����
	vCamera = model; //�J�����̈ʒu�����f���ƈ�v
	vCamera.z -= 80.0f;

	SetCameraPositionAndTargetAndUpVec(vCamera, model, VGet(0, 1, 0));

	//�J�����̃N���b�v�w��
	SetCameraNearFar(10, 1000);

	//����p��ݒ�
	SetupCamera_Perspective(PI/3);
}


Camera::~Camera()
{
}

//�J��������֐�
void Camera::CameraControl(const Player& player)const
{
}

//�J������]�֐�
void Camera::RotCamera(const VECTOR& vPlayer, VECTOR *vCamera, float arg)
{

}

void Camera::AddX(float x)
{
	vCamera.x += x;
}

void Camera::AddY(float y)
{
	vCamera.y += y;
}

void Camera::AddZ(float z)
{
	vCamera.z += z;
}