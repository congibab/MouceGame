# include <Siv3D.hpp>
#include "Enemy.h"
#include "ParticleSys.h"

using App = SceneManager<String>;

#pragma once
class Game : public App::Scene
{
private:
	int _Score;
	float Time; //ğ¤ùÚãÁÊà
	Enemy enemy;
	Font font;
	Effect effect;
	Texture texture;
public:

	Game(const InitData& init);
	void update() ;
	void draw() const;

};