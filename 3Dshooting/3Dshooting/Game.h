#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Fps.h"
#include "Camera.h"

class Game
{
private:
	int counter = 0;
	Player* player;
	//Enemy* enemy;
	Fps* fps;
	Camera* camera;
public:
	Game();
	~Game();
	void Run();
};

