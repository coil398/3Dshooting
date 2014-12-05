#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Fps.h"
class Game
{
private:
	int counter = 0;
	Player* player;
	//Enemy* enemy;
	Fps* fps;
public:
	Game();
	~Game();
	void Run();
};

