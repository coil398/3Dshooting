#include "Camera.h"
#include <DxLib.h>


Camera::Camera(Player* player)
{
	SetCameraPositionAndTargetAndUpVec(VGet(320, 400, -450), player->GetVector(), VGet(0, 1, 0));
}


Camera::~Camera()
{
}
