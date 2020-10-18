#pragma once
# include <Siv3D.hpp>
using App = SceneManager<String>;

class Title : public App::Scene
{
private:

public:
	Title(const InitData& init);
	void update();
	void draw() const;
};

