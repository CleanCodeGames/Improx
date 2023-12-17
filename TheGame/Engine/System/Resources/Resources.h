#pragma once
#include "Engine/System/Overhead.h"

class Texture : private std::unordered_map<std::string, std::unique_ptr<sf::Texture>>
{
    friend class Resources;

public:

    sf::Texture* Get(const std::string& name);
};

class Font : private std::unordered_map<std::string, std::unique_ptr<sf::Font>>
{
    friend class Resources;

public:

    sf::Font* Get(const std::string& name);
};

class Sound : private std::unordered_map<std::string, std::pair<sf::SoundBuffer, sf::Sound>>
{
    friend class Resources;

public:

    sf::SoundBuffer* GetBuffer(const std::string& name);
    sf::Sound* GetSound(const std::string& name);
};

class Music : private std::unordered_map<std::string, std::unique_ptr<sf::Music>>
{
    friend class Resources;

public:

    sf::Music* Get(const std::string& name);
};

class Audio
{
public:

    Sound sound;
    Music music;
    Audio() = default;
};

class Shader : private std::unordered_map<std::string, std::unique_ptr<sf::Shader>>
{
    friend class Resources;

public:

    sf::Shader* Get(const std::string& name);

};

class Resources
{
private:

    std::vector<std::filesystem::path> SerchPaths();
    std::vector<std::filesystem::path> ScanDirectory(const std::string& pathDir);
    void AddFile(std::filesystem::path path);

public:

    Texture texture;
    Shader shader;
    Audio audio;
    Font font;

    Resources();
};