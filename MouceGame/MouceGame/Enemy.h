# include <Siv3D.hpp>
#include "ParticleSys.h"

#pragma once
class Enemy
{
private:
	int Score;  //点数
	bool Delet; //敵を消えた判定
	float Time; //制限時間
	
	Font font;
	Effect effect; //ParticleEffect用変数
	
	//===================（敵、色、円、向き）関連データ
	Array<Vec2> enemies;
	Array<Color> color;
	Array<Circle> circle;
	Array<Vec2> Direction;
	//===================

	void Movement(); //敵の動き
	void Wall_collision();//壁の当たり判定
public:
	Enemy();
	void update();
	void draw() const;
	
	int GetScore() { return Score; } //GameSceneに渡す変数
	bool GetDelet() { return Delet; }//GameSceneに渡す変数
};

