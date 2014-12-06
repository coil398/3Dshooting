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
	Camera(const Player& player);
	~Camera();
	void MoveCamera();
	void AddZ(float z);
};

