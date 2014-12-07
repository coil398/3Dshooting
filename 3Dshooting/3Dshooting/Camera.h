#pragma once
#include "Player.h"
class Camera
{
private:
	int key;
	int modelHandle;
	VECTOR vCamera;
	VECTOR model;
public:
	Camera(VECTOR Eye);
	~Camera();
	void CameraControl(const Player& player)const;
	void Camera::RotCamera(const VECTOR& vPlayer, VECTOR *vCamera,float arg);
	void AddX(float x);
	void AddY(float y);
	void AddZ(float z);
};

