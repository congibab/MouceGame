# include <Siv3D.hpp>
# include "Title.h"
# include "Game.h"

void Main()
{
	FontAsset::Register(U"TitleFont", 60, Typeface::Heavy);
	App manager;

	manager.add<Title>(U"Title");
	manager.add<Game>(U"Game");


	while (System::Update())
	{
		if (!manager.update())
		{
			break;
		}
	}
}
