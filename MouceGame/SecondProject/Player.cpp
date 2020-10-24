#include "Player.h"

Player::Player() : Pos(400, 300)
{

}

void Player::update()
{
	if (!is_Ground)
	{
		Pos.y += Gravity;
	}

	if (KeyLeft.pressed())
	{
		Pos.x -= 50;
	}
}

void Player::draw() const
{
	Circle(Pos, radius).draw();
}
