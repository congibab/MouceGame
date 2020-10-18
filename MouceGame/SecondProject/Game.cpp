#include "Game.h"

Game::Game(const InitData& init) :IScene(init), rt(Scene::Size()), emojiCat(Emoji(U"🐈")), windmill(U"example/windmill.png", TextureDesc::Mipped),
psGrayscale(U"example/shader/2d/grayscale" SIV3D_SELECT_SHADER(U".hlsl", U".frag"),	{ { U"PSConstants2D", 0 } }),
ps(U"example/shader/2d/multi_texture_blend" SIV3D_SELECT_SHADER(U".hlsl", U".frag"),{ { U"PSConstants2D", 0 } })

{


}

void Game::update()
{
	if (!psGrayscale)
	{
	throw Error(U"Failed to load a shader file");
	}

}

void Game::draw() const
{
	rt.clear(ColorF(0.8, 0.9, 1.0));
	{
		ScopedRenderTarget2D target(rt);

		for (auto y : Range(1, 5))
		{
			Line(0, y * 100, 800, y * 100).draw(1, Palette::Gray);
		}

		for (auto x : Range(1, 7))
		{
			Line(x * 100, 0, x * 100, 600).draw(1, Palette::Gray);
		}

		Graphics2D::SetTexture(1, windmill);
		{
			// マルチテクスチャによるブレンドのシェーダを開始
			ScopedCustomShader2D shader(ps);
			emojiCat.scaled(2).drawAt(Scene::Center());
		}
	}
	Graphics2D::Flush();
	rt.resolve();
	ScopedCustomShader2D shader(psGrayscale);
	rt.draw();
}

