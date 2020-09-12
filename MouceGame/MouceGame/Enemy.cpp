#include "Enemy.h"

/// <summary>
/// 敵の動き
/// </summary>
void Enemy::Movement()
{
	for (auto i = 0; i < circle.size(); ++i)
	{
		Wall_collision();
		circle[i].moveBy(Direction[i] * Scene::DeltaTime() * 100);
	}
}

/// <summary>
/// 敵がスクリーン外に移動したら移動を反転する
/// </summary>
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

Enemy::Enemy() : font(30)
{
	Delet = false;
	Score = 0;
}

void Enemy::update()
{
	Delet = false;

	if (enemies.size() <= 20)//敵の数を20個に制限
	{
		enemies << RandomVec2(Scene::Rect());
		color << RandomColor();
		circle << Circle(enemies.back(), 30);
		Direction << Vec2(Random(-2, 2), Random(-2, 2));
	}
	
	
	int j = 0;
	for (auto i = circle.begin(); i < circle.end(); ++i)
	{	
		//マウスが円の上に位置するとRingEffectが出る
		if (i->mouseOver())
		{
			effect.add<RingEffect>(Cursor::Pos());
		}

		if (i->leftClicked()) //クリックすると敵を消える処理
		{
			circle.erase(i);
			color.erase(color.begin() + j);
			enemies.erase(enemies.begin() + j);
			Direction.erase(Direction.begin() + j);
			Score += 1;
			Delet = true;
			break;
		}
		j++;
	}
	Movement();
	effect.update();
}

void Enemy::draw() const
{
	for (auto i = 0; i < circle.size(); ++i)
	{
		circle[i].draw(color[i]);
	}
}
