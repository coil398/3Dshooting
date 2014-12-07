#include "Camera.h"
#include <DxLib.h>
#define PI 3.1415926
#include "CheckKeyh.h"
#include <math.h>


Camera::Camera(const Player& player)
{

	model = player.GetVector(); //モデルの座標を取得
	model.y -= -75.0f; //モデルの中心を上に
	vCamera = model; //カメラの位置をモデルと一致
	vCamera.z -= 80.0f;

	SetCameraPositionAndTargetAndUpVec(vCamera, model, VGet(0, 1, 0));

	//カメラのクリップ指定
	SetCameraNearFar(10, 1000);

	//視野角を設定
	SetupCamera_Perspective(PI/3);
}


Camera::~Camera()
{
}

//カメラ操作関数
void Camera::CameraControl(const Player& player)
{
	if (CheckKey::Key[KEY_INPUT_A] >= 1) RotCamera(player.GetVector(),&vCamera,0.01f);
	if (CheckKey::Key[KEY_INPUT_D] >= 1) RotCamera(player.GetVector(), &vCamera,-0.01f);;
	
	/*
	key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (key & PAD_INPUT_DOWN) AddZ(-1.0f); //奥行き
	if (key & PAD_INPUT_UP) AddZ(1.0f);
	if (key & PAD_INPUT_LEFT) AddX(-1.0f); //左右
	if (key & PAD_INPUT_RIGHT) AddX(1.0f);
	*/

	SetCameraPositionAndTargetAndUpVec(vCamera, model, VGet(0, 1, 0));
}

//カメラ回転関数
void Camera::RotCamera(const VECTOR& vPlayer, VECTOR *vCamera, float arg)
{
	const float dx = vCamera->x - vPlayer.x,
		dz = vCamera->z - vPlayer.z;
	vCamera->x = dx * cos(arg) + dz * sin(arg);
	vCamera->z = -dx * sin(arg) + dz * cos(arg);
	vCamera->x += vPlayer.x;
	vCamera->z += vPlayer.z;
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