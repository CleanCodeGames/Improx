#pragma once
#include "Engine/System/System.h"
#include "Gameplay/Suspect/Suspect.h"
#include "Gameplay/Levels/oLevel.h"

class Game : public URA
{
	DECLARATION_URA(Game, public)
	void Play();
	
private:

	std::unordered_map<std::string, std::unique_ptr<oLevel>> levels;
	std::unique_ptr<oLevel> current_level;
};