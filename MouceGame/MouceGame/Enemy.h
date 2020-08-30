# include <Siv3D.hpp>

#pragma once
class Enemy
{
private:
	float Time; //ğ¤ùÚãÁÊà
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
};

