#pragma once
#include "Player.h"
class Camera
{
private:
	int modelHandle;
	VECTOR model;
public:
	Camera(const Player& player);
	~Camera();
};

