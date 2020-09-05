# include <Siv3D.hpp>
#include "ParticleSys.h"

#pragma once
class Enemy
{
private:
	int Score;
	bool Delet;
	float Time; //�������
	
	Font font;
	Effect effect;
	Array<Vec2> enemies;
	Array<Color> color;
	Array<Circle> circle;
	Array<Vec2> Direction;

	void Movement();
	void Wall_collision();
public:
	Enemy();
	void update();
	void draw() const;
	
	int GetScore() { return Score; }
	bool GetDelet() { return Delet; }
};

