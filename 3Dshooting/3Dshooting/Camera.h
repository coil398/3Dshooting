#pragma once
#include "Player.h"
#include "BackGround.h"
class Camera
{
private:
	int key;
	int modelHandle;
	VECTOR vCamera;
	VECTOR model;
	VECTOR lookAt;
	float angleH; //êÖïΩäpìx
	float angleV; //êÇíºäpìx
public:
	Camera(const Player& player,VECTOR eye);
	~Camera();
	void CameraControl(const Player& player)const;
	void Camera::RotCamera(const VECTOR& vPlayer, VECTOR *vCamera,float arg);
	void AddX(float x);
	void AddY(float y);
	void AddZ(float z);
	void Process(int* nowInput, Player* player, VECTOR* eye,BackGround* stage);
	void Process();
};

