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

//カメラ操作関数
void Camera::MoveCamera()
{
	SetCameraPositionAndTargetAndUpVec(vCamera, model, VGet(0, 1, 0));
	if (CheckKey::Key[KEY_INPUT_A] >= 1) AddX(1.0f);
	if (CheckKey::Key[KEY_INPUT_D] >= 1) AddX(-1.0f);
	if (CheckKey::Key[KEY_INPUT_S] >= 1) AddY(1.0f);
	if (CheckKey::Key[KEY_INPUT_W] >= 1) AddY(-1.0f);
	if (CheckKey::Key[KEY_INPUT_Q] >= 1) AddZ(1.0f);
	if (CheckKey::Key[KEY_INPUT_E] >= 1) AddZ(-1.0f);
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