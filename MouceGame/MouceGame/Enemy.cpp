#include "Enemy.h"

void Enemy::Movement()
{
	for (auto i = 0; i < circle.size(); ++i)
	{
		Wall_collision();
		circle[i].moveBy(Direction[i] * Scene::DeltaTime() * 10);
	}
}

void Enemy::Wall_collision()
{
	for (auto i = 0; i < circle.size(); ++i)
	{
		if ((circle[i].x < 0 && Direction[i].x < 0) || (Scene::Width() < circle[i].x && Direction[i].x > 0))
		{
			Direction[i].x *= -1;
		}

		if ((circle[i].y < 0 && Direction[i].y < 0) || (Scene::Height() < circle[i].y && Direction[i].y > 0))
		{
			Direction[i].y *= -1;
		}
	}
}

Enemy::Enemy()
{
	Score = 0;
}

void Enemy::update()
{
	if (enemies.size() <= 10) enemies << RandomVec2(Scene::Rect());
	if (color.size() <= 10) color << RandomColor();
	if (circle.size() <= 10) circle << Circle(enemies.back(), 20);
	if (Direction.size() <= 10) Direction << Vec2(Random(-10,10), Random(-10, 10));
	
	
	int j = 0;
	for (auto i = circle.begin(); i < circle.end(); ++i)
	{
		
		if (i->leftClicked())
		{
			circle.erase(i);
			color.erase(color.begin() + j);
			enemies.erase(enemies.begin() + j);
			Direction.erase(Direction.begin() + j);
			effect.add<Spark>(Cursor::Pos());

			Score += 1;
			break;
		}
		j++;
	}
	effect.update();
	Movement();
	
}

void Enemy::draw() const
{
	//Print << U"{}"_fmt(enemies);
	for (auto i = 0; i < circle.size(); ++i)
	{
		circle[i].draw(color[i]);
	}
	

}
