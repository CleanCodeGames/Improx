#pragma once
#include "../System.h"

struct Input
{
	struct Keyboard
	{
		static bool Pressed(const sf::Keyboard::Key key);
		static bool Released(const sf::Keyboard::Key key);
	};

	struct Mouse
	{
		static bool Pressed(const sf::Mouse::Button key);
		static bool Released(const sf::Mouse::Button key);
	};
};