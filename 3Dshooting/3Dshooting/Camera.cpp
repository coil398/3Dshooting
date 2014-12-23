#include "Camera.h"
#include <math.h>

Camera::Camera()
{
	/*
	cameraVector = lookAt;
	cameraVector.z += 40.0f;
	cameraVector.y += 20.0f;

	lookAt.y += 20.0f;

	SetCameraPositionAndTargetAndUpVec(cameraVector, lookAt, VGet(0, 1, 0));

	SetCameraNearFar(0.0f, 10000.0);
	*/
	//�J�����̃N���b�v�w��
	SetCameraNearFar(1.0f, 25000.0f);
	//����p��ݒ�
	SetupCamera_Perspective(DX_PI_F / 3);
}

Camera::~Camera()
{
	
}

void Camera::Move(VECTOR move,VECTOR lookAt)
{
	cameraVector = move;
	cameraVector.x += 10.0f;
	cameraVector.z += 40.0f;
	cameraVector.y += 20.0f;

	lookAt.y += 20.0f;

	SetCameraPositionAndTargetAndUpVec(cameraVector, lookAt, VGet(0, 1, 0));

	//SetCameraNearFar(0.0f, 10000.0);
}