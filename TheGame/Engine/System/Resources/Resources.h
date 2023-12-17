#pragma once
#include "Engine/System/Overhead.h"

class Texture : private std::unordered_map<std::string, std::unique_ptr<sf::Texture>>
{
    friend class Resources;

public:

    sf::Texture* get(const std::string& name);
};

class Font : private std::unordered_map<std::string, std::unique_ptr<sf::Font>>
{
    friend class Resources;

public:

    sf::Font* get(const std::string& name);
};

class Sound : private std::unordered_map<std::string, std::pair<sf::SoundBuffer, sf::Sound>>
{
    friend class Resources;

public:

    sf::SoundBuffer* getBuffer(const std::string& name);
    sf::Sound* getSound(const std::string& name);
};

class Music : private std::unordered_map<std::string, std::unique_ptr<sf::Music>>
{
    friend class Resources;

public:

    sf::Music* get(const std::string& name);
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

    sf::Shader* get(const std::string& name);

};

class Resources
{
private:

    std::vector<std::filesystem::path> serchPaths();
    std::vector<std::filesystem::path> scanDirectory(const std::string& pathDir);
    void addFile(std::filesystem::path path);

public:

    Texture texture;
    Shader shader;
    Audio audio;
    Font font;

    Resources();
};