# include <Siv3D.hpp>

using App = SceneManager<String>;

#pragma once
class Title : public App::Scene
{
private:
	 double t;
public:
	Title(const InitData& init);
	void update();
	void draw() const ;
};

