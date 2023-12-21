#pragma once
#include "Resources/Resources.h"

class System
{
public:

	static std::unique_ptr<sf::RenderWindow> window;
	static std::unique_ptr<sf::Event> event;
	static std::unique_ptr<sf::Clock> clock;
	static std::unique_ptr<sf::View> camera;
	static std::unique_ptr<Resources> resources;

	static sf::Vector2i resolution;
	static sf::Vector2f camera_position;
	static sf::Vector2f cursor_world;
	static sf::Vector2f cursor_window;
	static float time_elapsed;

	static void Initialization();
	static void Update();

	System() = delete;
	~System() = delete;
};

#define TEXTURE(file_name) System::resources->texture.Get(file_name)
#define SOUND(file_name) System::resources->audio.sound.GetSound(file_name)
#define SOUND_BUFFER(file_name) System::resources->audio.sound.GetBuffer(file_name)
#define MUSIC(file_name) System::resources->audio.music.Get(file_name)
#define FONT(file_name) System::resources->font.Get(file_name)
#define SHADER(file_name) System::resources->shader.Get(file_name)