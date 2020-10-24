#include "Game.h"


Game::Game(const InitData& init) :IScene(init), rt(Scene::Size()), emojiCat(Emoji(U"🐈")), windmill(U"example/windmill.png", TextureDesc::Mipped),
psGrayscale(U"example/shader/2d/grayscale" SIV3D_SELECT_SHADER(U".hlsl", U".frag"),	{ { U"PSConstants2D", 0 } }),
ps(U"example/shader/2d/multi_texture_blend" SIV3D_SELECT_SHADER(U".hlsl", U".frag"),{ { U"PSConstants2D", 0 } })

{
	if (!psGrayscale)
	{
		throw Error(U"Failed to load a shader file");
	}

}

void Game::update()
{
	if (Scene::Height() <= player.getPos().y + 25)
	{
		player.Set_is_Ground(true);
	}
	player.update();
	block.update();
}

void Game::draw() const
{
	rt.clear(ColorF(0.8, 0.9, 1.0));
	{
		ScopedRenderTarget2D target(rt);

		Graphics2D::SetTexture(1, windmill);
		{
			// マルチテクスチャによるブレンドのシェーダを開始
			ScopedCustomShader2D shader(ps);
			emojiCat.scaled(2).drawAt(Scene::Center());
		}
		player.draw();
		block.draw();
		
	}
	Graphics2D::Flush();
	rt.resolve();
	//post Processing shader
	//ScopedCustomShader2D shader(psGrayscale);
	rt.draw();
}

