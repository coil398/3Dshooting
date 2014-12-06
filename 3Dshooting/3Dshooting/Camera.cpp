#include "Camera.h"
#include <DxLib.h>
#define PI 3.1415926
#include "CheckKeyh.h"


Camera::Camera(const Player& player)
{
	model = player.GetVector();
	model.y -= -75.0f;
	vCamera = VGet(640, 540, -800);

	//カメラのクリップ指定
	SetCameraNearFar(10, 1000);

	//視野角を設定
	SetupCamera_Perspective(PI/3);
}


Camera::~Camera()
{
}

void Camera::MoveCamera()
{
	SetCameraPositionAndTargetAndUpVec(vCamera, model, VGet(0, 1, 0));
	if (CheckKey::Key[KEY_INPUT_Q] >= 1) AddZ(1.0f);
	if (CheckKey::Key[KEY_INPUT_W] >= 1) AddZ(-1.0f);
}

void Camera::AddZ(float z)
{
	vCamera.z += z;
}