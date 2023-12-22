#pragma once
#include "Engine/System/System.h"
#include "Gameplay/Suspect/Suspect.h"
class Game
{
private:

	void Update();
	void Render();
	void Action();

	std::unique_ptr<Suspect> suspect;

public:

	void Play();

	Game();
	~Game();
};

