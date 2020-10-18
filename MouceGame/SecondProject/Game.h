#pragma once
# include <Siv3D.hpp>
using App = SceneManager<String>;

class Game : public App::Scene
{
private:
	MSRenderTexture rt;
	const PixelShader psGrayscale;
	const PixelShader ps;
	const Texture emojiCat;
	const Texture windmill;
public:
	Game(const InitData& init);
	void update();
	void draw() const;
};

