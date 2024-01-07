#pragma once
#include <Engine/System/System.h>

class WorldSettings
{
private:

	b2Vec2 gravity = { 0.0f, 0.98f };
	b2World world = { gravity };

protected:

public:

	WorldSettings();
	~WorldSettings();

};

