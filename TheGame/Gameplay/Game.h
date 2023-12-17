#pragma once
#include "Engine/System/System.h"

class Game
{
private:

	void Update();
	void Render();
	void Action();

	sf::VertexArray vArr;

	//std::vector<std::unique_ptr<ILevel>> vec_level;

public:

	void Play();

	Game();
	~Game();
};

