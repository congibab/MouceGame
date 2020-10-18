#pragma once
# include <Siv3D.hpp>
using App = SceneManager<String>;

class Result : public App::Scene
{
private:

public:
	Result(const InitData& init);
	void update();
	void draw() const;
};

