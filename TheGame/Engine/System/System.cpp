#include "System.h"

std::unique_ptr<sf::RenderWindow>	System::window;
std::unique_ptr<sf::Event>			System::event;
std::unique_ptr<sf::Clock>			System::clock;
std::unique_ptr<sf::View>			System::camera;
std::unique_ptr<Resources>			System::resources;

sf::Vector2i						System::resolution;
sf::Vector2f						System::camera_position;
sf::Vector2f						System::cursor_world;
sf::Vector2f						System::cursor_window;

float								System::time_elapsed;

void System::Initialization()
{
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;

	resources	= std::make_unique<Resources>();
	window		= std::make_unique<sf::RenderWindow>(sf::VideoMode(static_cast<int>(resolution.x * 0.75), static_cast<int>(resolution.y * 0.75)), L"The game", sf::Style::Default);
	event		= std::make_unique<sf::Event>();
	clock		= std::make_unique<sf::Clock>();
	camera		= std::make_unique<sf::View>();
	//window->setFramerateLimit(60);
	//window->setVerticalSyncEnabled(true);
	camera->setSize(static_cast<float>(resolution.x), static_cast<float>(-resolution.y));
	camera->setCenter(0, 0);
	window->setView(*camera);
	time_elapsed = 0.f;
}

void System::Update()
{
	time_elapsed = clock->getElapsedTime().asSeconds();
	clock->restart();
	camera_position = camera->getCenter();
	cursor_world = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
	cursor_window = sf::Vector2f(sf::Mouse::getPosition(*window));
}

IOpenClose::IOpenClose(bool is_open) : is_open(is_open) {}
void IOpenClose::Open() { is_open = true; }
void IOpenClose::Close() { is_open = false; }