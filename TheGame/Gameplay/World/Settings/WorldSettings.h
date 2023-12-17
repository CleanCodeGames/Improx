#pragma once
#include <Engine/System/System.h>

class WorldSettings
{
private:

	float gravity; // lower 0.9 > 1.0 normal < 1.1 upped
	std::pair<float, float> force;

protected:

	void SetForce(const float direction, const float intensity);
	void SetGravity();

public:

	WorldSettings();


};

