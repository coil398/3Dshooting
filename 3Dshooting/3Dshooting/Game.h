#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Fps.h"
#include "Camera.h"
#include "BackGround.h"

class Game
{
private:
	int counter = 0;
	Player* player;
	//Enemy* enemy;
	BackGround* stage;
	Fps* fps;
	Camera* camera;
public:
	Game();
	~Game();
	void Run();
};

