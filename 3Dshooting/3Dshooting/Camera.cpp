#include "Camera.h"
#include <DxLib.h>
#define PI 3.1415926


Camera::Camera(const Player& player)
{
	model = player.GetVector();
	model.y -= -75.0f;
	SetCameraPositionAndTargetAndUpVec(VGet(640, 540, -800), model, VGet(0, 1, 0));

	//�J�����̃N���b�v�w��
	SetCameraNearFar(10, 200);

	//����p��ݒ�
	SetupCamera_Perspective(PI/3);
}


Camera::~Camera()
{
}
