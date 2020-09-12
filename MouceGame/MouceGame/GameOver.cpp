#include "GameOver.h"

GameOver::GameOver(const InitData& init) : IScene(init), font(30)
{
}

void GameOver::update()
{
	if (MouseL.pressed()) changeScene(U"Title");
}

void GameOver::draw() const
{
	FontAsset(U"TitleFont")(U"ゲームオーヴァー").drawAt(400, 100);
	font(U"マウス右クリックぢてタイトルに戻る").drawAt(400, 500, ColorF(1)); //制限時間表示
}
