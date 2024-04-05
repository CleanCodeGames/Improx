#pragma once
#include <Engine/System/System.h>
#include "Gameplay/B2Objects/B2Object.h"

class Pool
{
public:
	bool is_awake;

};

class Weather
{
public:

	std::vector<sf::RectangleShape> vec_shape;
};

class WorldSettings
{
public:

	b2Vec2 gravity = { 0.0f, 0.98f };
	b2Vec2 force = { 0.0f, 0.0f };
	b2World world = { gravity };
	std::string weather;
	void RunWeather(const std::string& weather);

	WorldSettings(const b2Vec2 gravity, const std::string& weather = "default");
	~WorldSettings();
};

