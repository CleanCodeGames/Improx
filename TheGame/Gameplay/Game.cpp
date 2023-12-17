#include "Game.h"
#include "Engine/System/Input/Input.h"

Game::Game()
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
	// Write game logic updating code...
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
	sf::RectangleShape shape(sf::Vector2f(200, 200));
	shape.setOrigin(shape.getSize() / 2.f);
	shape.setTexture(TEXTURE("test"));
	System::window->clear();
	System::window->draw(vArr);
	System::window->draw(shape);
	System::window->display();
}



Game::~Game()
{

}