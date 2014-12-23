#pragma once
#include "Player.h"

class Camera
{
private:
	float theta;
public:
	VECTOR cameraVector;
	Camera();
	~Camera();
	void Move(VECTOR move,VECTOR lookAt);
};