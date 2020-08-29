#include "Title.h"

Title::Title(const InitData& init) : IScene(init)
{

}

void Title::update()
{
	t = Scene::Time();
	//if (MouseL.down()) changeScene(U"Game");
	if (SimpleGUI::Button(U"game start", Scene::Center() + Vec2(-250,0), 500)) changeScene(U"Game");

}

void Title::draw() const
{
	Scene::SetBackground(ColorF(0.3, 0.4, 0.5));

	Print << U"{}"_fmt(t);

	FontAsset(U"TitleFont")(U"マウスで図形を消すゲーム").drawAt(400, 100);
}
