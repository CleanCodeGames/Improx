#include "Game.h"
#include "Engine/System/Input/Input.h"

Game::Game(void)
{
	System::Initialization();
}

void Game::Play()
{
	while (System::window->isOpen())
	{
		Update();
		Action();
		Render();
	}
}

void Game::Update()
{
	System::Update();
}

void Game::Action()
{
	while (System::window->pollEvent(*System::event))
	{
		const auto is_exit = (System::event->type == sf::Event::Closed || Input::Keyboard::Pressed(sf::Keyboard::Key::Escape));
		if (is_exit) System::window->close();
	}
}

void Game::Render()
{
	System::window->clear();

	System::window->display();
}



Game::~Game()
{
}