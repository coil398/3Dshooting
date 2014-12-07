#include "Camera.h"
#include <DxLib.h>
#define PI 3.1415926
#include "CheckKeyh.h"
#include <math.h>


Camera::Camera(const Player& player)
{

	model = player.GetVector(); //���f���̍��W���擾
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
void Camera::CameraControl(const Player& player)
{
<<<<<<< HEAD
	/*
	SetCameraPositionAndTargetAndUpVec(vCamera, model, VGet(0, 1, 0));
	if (CheckKey::Key[KEY_INPUT_A] >= 1) AddX(1.0f);
	if (CheckKey::Key[KEY_INPUT_D] >= 1) AddX(-1.0f);
	if (CheckKey::Key[KEY_INPUT_S] >= 1) AddY(1.0f);
	if (CheckKey::Key[KEY_INPUT_W] >= 1) AddY(-1.0f);
	if (CheckKey::Key[KEY_INPUT_Q] >= 1) AddZ(1.0f);
	if (CheckKey::Key[KEY_INPUT_E] >= 1) AddZ(-1.0f);
	*/
=======
	if (CheckKey::Key[KEY_INPUT_A] >= 1) RotCamera(player.GetVector(),&vCamera,0.01f);
	if (CheckKey::Key[KEY_INPUT_D] >= 1) RotCamera(player.GetVector(), &vCamera,-0.01f);;
	
	/*
	key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (key & PAD_INPUT_DOWN) AddZ(-1.0f); //���s��
	if (key & PAD_INPUT_UP) AddZ(1.0f);
	if (key & PAD_INPUT_LEFT) AddX(-1.0f); //���E
	if (key & PAD_INPUT_RIGHT) AddX(1.0f);
	*/

	SetCameraPositionAndTargetAndUpVec(vCamera, model, VGet(0, 1, 0));
}

//�J������]�֐�
void Camera::RotCamera(const VECTOR& vPlayer, VECTOR *vCamera, float arg)
{
	const float dx = vCamera->x - vPlayer.x,
		dz = vCamera->z - vPlayer.z;
	vCamera->x = dx * cos(arg) + dz * sin(arg);
	vCamera->z = -dx * sin(arg) + dz * cos(arg);
	vCamera->x += vPlayer.x;
	vCamera->z += vPlayer.z;
>>>>>>> origin/master
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