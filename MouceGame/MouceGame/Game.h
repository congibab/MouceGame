# include <Siv3D.hpp>
#include "Enemy.h"

using App = SceneManager<String>;

#pragma once
class Game : public App::Scene
{
private:
	float Time; //ğ¤ùÚãÁÊà
	Enemy enemy;

public:
	Game(const InitData& init);
	void update() ;
	void draw() const ;

};