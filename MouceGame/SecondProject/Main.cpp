
#include <Siv3D.hpp> // OpenSiv3D v0.4.3
#include <mysql.h>

#include "Title.h"
#include "Game.h"
#include "Result.h"

#pragma comment(lib, "libmariadb.lib")

void Main()
{
	//constexpr ColorF backgroundColor(0.3, 0.4, 0.5);
	//MSRenderTexture rt(Scene::Size());

	//const PixelShader psGrayscale(U"example/shader/2d/grayscale" SIV3D_SELECT_SHADER(U".hlsl", U".frag"),
	//	{ { U"PSConstants2D", 0 } });

	//const PixelShader ps(U"example/shader/2d/multi_texture_blend" SIV3D_SELECT_SHADER(U".hlsl", U".frag"),
	//	{ { U"PSConstants2D", 0 } });

	//const Texture emojiCat(Emoji(U"🐈"));
	//const Texture windmill(U"example/windmill.png", TextureDesc::Mipped);

	//MYSQL* con = mysql_init(NULL);

	//if (con == NULL)
	//{
	//	fprintf(stderr, "%s\n", mysql_error(con));
	//	exit(1);
	//}

	//if (mysql_real_connect(con, "ip adrass", "Username", "password",
	//	"DBName", 0, NULL, 0) == NULL)
	//{
	//	fprintf(stderr, "%s\n", mysql_error(con));
	//	throw Error(U"not connect server");
	//	mysql_close(con);
	//}

	App manager;

	//=========================add Scene
	//manager.add<Title>(U"Title");
	manager.add<Game>(U"Game");
	manager.add<Result>(U"Result");
	//=========================

	while (System::Update())
	{
	
		if (!manager.update())
		{
			break;
		}
	
	}
}