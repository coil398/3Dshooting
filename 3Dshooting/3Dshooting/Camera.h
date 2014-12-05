#pragma once
#include "Player.h"
class Camera
{
private:
	int modelHandle;
	Player* model;
public:
	Camera(Player* player);
	~Camera();
};

