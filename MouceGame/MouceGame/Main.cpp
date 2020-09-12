# include <Siv3D.hpp>
# include "Title.h"
# include "Game.h"
# include "GameOver.h"

void Main()
{
	//Title Name
	FontAsset::Register(U"TitleFont", 60, Typeface::Heavy);
	App manager;

	//=========================add Scene
	manager.add<Title>(U"Title");
	manager.add<Game>(U"Game");
	manager.add<GameOver>(U"GameOver");
	//=========================

	while (System::Update())
	{
		if (!manager.update())
		{
			break;
		}
	}
}