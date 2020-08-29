# include <Siv3D.hpp>

using App = SceneManager<String>;

#pragma once
class Game : public App::Scene
{
private:

	Texture tex;
public:
	Game(const InitData& init);
	void update() ;
	void draw() const ;
};