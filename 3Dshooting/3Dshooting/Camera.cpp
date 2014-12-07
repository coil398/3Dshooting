#include "Camera.h"
#include <DxLib.h>
#define PI 3.1415926
#include "CheckKeyh.h"
#include <math.h>


Camera::Camera(VECTOR Eye)
{

	model = Eye; //モデルの座標を取得
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
void Camera::CameraControl(const Player& player)const
{
}

//カメラ回転関数
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