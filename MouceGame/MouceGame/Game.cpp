#include "Game.h"

Game::Game(const InitData& init) : IScene(init), enemy() ,
									font1(30) ,  font2(50, Typeface::Heavy),
									texture(Emoji(U" 🔨 ")), rt(Scene::Size())//,
									//ps(U"example/shader/2d/grayscale" SIV3D_SELECT_SHADER(U".hlsl", U".frag"),{ { U"PSConstants2D", 0 } })
{
	_Delet = enemy.GetDelet();
	Time = 30;

	//if (!ps) throw Error(U"Failed to load a shader file");
}

void Game::update()
{
	rt.clear(ColorF(1, 1, 1));
	ScopedRenderTarget2D target(rt);


	if (Time <= 0) changeScene(U"Title");
	Time -= Scene::DeltaTime();
	enemy.update();
	_Score = enemy.GetScore();	
	_Delet = enemy.GetDelet();
}

void Game::draw() const
{
	//Scene::SetBackground(ColorF(1,1,1));

	if (_Delet)
	{
		effect.add<Spark>(Cursor::Pos());
		effect.add<NumberEffect>(Cursor::Pos(), _Score, font2);
	}
	effect.update();
	enemy.draw();

	font1(U"制限時間 = {:.1f}"_fmt(Time)).draw(50, 500, ColorF(0.25));
	//font1(U"点数 = {}"_fmt(_Score)).draw(500, 50, ColorF(0.25));

	//Graphics2D::Flush();
	//rt.resolve();

	//ScopedCustomShader2D shader(ps);
	//rt.draw();
}