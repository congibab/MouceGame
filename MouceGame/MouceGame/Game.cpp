#include "Game.h"

Game::Game(const InitData& init) : IScene(init), enemy(),font(30)
{
	Time = 60;
}

void Game::update()
{
	if (Time <= 0) changeScene(U"Title");
	Time -= Scene::DeltaTime();
	enemy.update();
	_Score = enemy.GetScore();
}

void Game::draw() const
{
	//Scene::SetBackground(ColorF(0.2, 0.8, 0.6));
	enemy.draw();
	font(U"制限時間 = {:.1f}"_fmt(Time)).draw(50, 500, ColorF(0.25));
	font(U"点数 = {}"_fmt(_Score)).draw(500, 50, ColorF(0.25));
}