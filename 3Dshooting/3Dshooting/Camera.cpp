#include "Camera.h"
#include <DxLib.h>


Camera::Camera(Player* player)
{
	model = player->GetVector();
	model.y -= -75.0f;
	SetCameraPositionAndTargetAndUpVec(VGet(640, 540, -800), model, VGet(0, 1, 0));
}


Camera::~Camera()
{
}
