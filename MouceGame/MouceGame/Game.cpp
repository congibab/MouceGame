#include "Game.h"

Game::Game(const InitData& init) : IScene(init)
{
	Time = 10;
	Enemy();
}

void Game::update()
{
	if (Time <= 0) changeScene(U"Title");
	ClearPrint();
	Time -= Scene::DeltaTime();

	enemy.update();
}

void Game::draw() const
{
	Scene::SetBackground(ColorF(0.2, 0.8, 0.6));
	Print << U"{}"_fmt(Time);
	enemy.draw();
}