# include <Siv3D.hpp>

using App = SceneManager<String>;

#pragma once
class GameOver : public App::Scene
{
private:
	Font font;
public:
	GameOver(const InitData& init);
	void update();
	void draw() const;
};

