#pragma once
#include "Engine/System/Utils_b2d.h"
#include "Gameplay/Levels/oLevel.h"

CLASSURA_ADDITION(Game,
	void Play();
private:
	std::unique_ptr<oLevel> current_level;
)