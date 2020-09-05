# include <Siv3D.hpp>
#include "Enemy.h"
#include "ParticleSys.h"

using App = SceneManager<String>;

#pragma once
class Game : public App::Scene
{
private:
	int _Score;  //EnemyClassのScore変数をコピー 用
	bool _Delet; //EnemyClassのDelet変数をコピー 用
	float Time;  //制限時間

	Enemy enemy;
	Font font1;
	Font font2;
	Effect effect;
	Texture texture;
	//PixelShader ps;
	
	//MSRenderTexture rt;

public:

	Game(const InitData& init);
	void update();
	void draw() const;

};