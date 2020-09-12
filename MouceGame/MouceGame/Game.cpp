#include "Game.h"

Game::Game(const InitData& init) : IScene(init), enemy() ,
									font1(30) ,  font2(50, Typeface::Heavy)									
{
	_Delet = enemy.GetDelet();
	Time = 30;
}

void Game::update()
{
	//時間が切れたらGameOver Sceneに移動
	if (Time <= 0) changeScene(U"GameOver");
	Time -= Scene::DeltaTime();
	
	enemy.update();
	_Score = enemy.GetScore();//点数をCopy
	_Delet = enemy.GetDelet();//敵が消えた判定Copy
}

void Game::draw() const
{
	//敵が消えたら
	if (_Delet)
	{
		effect.add<Spark>(Cursor::Pos()); //敵を消えたEffet
		effect.add<NumberEffect>(Cursor::Pos(), _Score, font2); //敵を倒した数をEffectに表示
	}
	effect.update();
	enemy.draw();

	font1(U"制限時間 = {:.1f}"_fmt(Time)).draw(50, 500, ColorF(0.25)); //制限時間表示
}