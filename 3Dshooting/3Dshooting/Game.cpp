#include "Game.h"
#include "dxlib.h"
#include "Player.h"
#include "Enemy.h"
#include "Vector3.h"
#include "fps.h"


Game::Game()
{
	player = new Player(640.0f, 420.0f, -700.0f, 100);
	fps = new Fps();
}


Game::~Game()
{
	delete player;
	//delete enemy;
	delete fps;
}

//ƒQ[ƒ€Às
void Game::Run()
{
	player->Move();

	player->Rot();

	player->Draw();

	fps->Update();
	fps->Draw();

	counter++;
}
