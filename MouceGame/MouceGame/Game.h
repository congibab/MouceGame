# include <Siv3D.hpp>
#include "Enemy.h"
#include "ParticleSys.h"

using App = SceneManager<String>;

#pragma once
class Game : public App::Scene
{
private:
	int _Score;
	float Time; //�������
	Enemy enemy;
	Font font;
	Effect effect;
public:

	Game(const InitData& init);
	void update() ;
	void draw() const;

};