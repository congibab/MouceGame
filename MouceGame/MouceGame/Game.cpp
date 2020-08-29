#include "Game.h"

Game::Game(const InitData& init) : IScene(init) , tex(Emoji(U"🐈"))
{
}

void Game::update()
{
	if (MouseL.down()) changeScene(U"Title");
}

void Game::draw() const
{
	Scene::SetBackground(ColorF(0.2, 0.8, 0.6));

	tex.drawAt(Cursor::Pos());
}
