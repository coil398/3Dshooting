#pragma once
#include "Player.h"
class Camera
{
private:
	int modelHandle;
	VECTOR model;
public:
	Camera(Player* player);
	~Camera();
};

