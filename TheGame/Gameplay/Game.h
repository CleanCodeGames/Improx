#pragma once
#include "Engine/System/Utils_b2d.h"
#include "Gameplay/Suspect/Suspect.h"
#include "Gameplay/Levels/oLevel.h"

class Game : public URA
{
	DECLURA(Game, public)
	void Play();
	
private:

	std::unordered_map<std::string, std::unique_ptr<oLevel>> levels;
	std::unique_ptr<oLevel> current_level;
};