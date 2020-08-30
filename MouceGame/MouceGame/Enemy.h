# include <Siv3D.hpp>

#pragma once
class Enemy
{
private:
	float Time; //ğ¤ùÚãÁÊà
	Array<Vec2> enemies;

	void Movement();
public:
	Enemy();
	void update();
	void draw() const;
};

