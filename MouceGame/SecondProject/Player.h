#pragma once
# include <Siv3D.hpp>

class Player
{
private:
	Vec2 Pos;
	Circle cir;

	float Gravity = 5;
	float radius = 25.0f;
	bool is_Ground = false;

public:
	Player();
	void update();
	void draw() const;

	Vec2 getPos() { return Pos; };
	float Area_y() { return Pos.y + radius; };

	bool Get_is_Ground() { return is_Ground; };
	void Set_is_Ground(bool val) { is_Ground = val; };
};