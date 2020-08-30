#include "Enemy.h"

void Enemy::Movement()
{
}

Enemy::Enemy()
{
	enemies << RandomVec2(800.0, 600.0);
}

void Enemy::update()
{
	enemies << RandomVec2(800.0, 600.0);
}

void Enemy::draw() const
{
	Print << U"{}"_fmt(enemies.front());

}
