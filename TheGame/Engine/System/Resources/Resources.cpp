#include "Resources.h"

const size_t NumFilesInFolder(const char* path)
{
    return std::distance(std::filesystem::directory_iterator(path), std::filesystem::directory_iterator{});
}

sf::Texture* Texture::get(const std::string& name)
{
    const auto& it = find(name);
    return it != end() ? it->second.get() : nullptr;
}

sf::Font* Font::get(const std::string& name)
{
    const auto& it = find(name);
    return it != end() ? it->second.get() : nullptr;
}

sf::Sound* Sound::getSound(const std::string& name)
{
    const auto& it = find(name); 
    return it != end() ? &it->second.second : nullptr;
}

sf::SoundBuffer* Sound::getBuffer(const std::string& name)
{
    const auto& it = find(name); 
    return it != end() ? &it->second.first : nullptr;
}

sf::Music* Music::get(const std::string& name)
{
   const auto& it = find(name); 
   return it != end() ? it->second.get() : nullptr;
}

sf::Shader* Shader::get(const std::string& name)
{
    const auto& it = find(name); 
    return it != end() ? it->second.get() : nullptr;
}

Resources::Resources()
{
    auto Paths = serchPaths();
    for (size_t i = 0; i < Paths.size(); ++i)
        addFile(Paths[i]);

    texture.rehash(texture.size());
    font.rehash(font.size());
    audio.sound.rehash(audio.sound.size());
    audio.music.rehash(audio.music.size());
    shader.rehash(shader.size());
}

std::vector<std::filesystem::path> Resources::serchPaths()
{
    std::vector<std::filesystem::path> paths = scanDirectory((std::filesystem::current_path() / "resources").string());
    return paths;
}

std::vector<std::filesystem::path> Resources::scanDirectory(const std::string& pathDir)
{
    std::vector<std::filesystem::path> filesA;
    std::vector vec_extensions{ ".png", ".jpg", ".jpeg", ".wav", ".ogg", ".ttf", ".otf", ".vert", ".frag" };
    for (std::filesystem::directory_iterator it(pathDir); it != std::filesystem::end(it); it++)
    {
        if (it->is_directory())
        {
            std::vector<std::filesystem::path> filesB = scanDirectory(it->path().string());
            filesA.insert(end(filesA), std::begin(filesB), std::end(filesB));
        }
        for (auto& exp : vec_extensions)
            if (it->path().extension() == exp)
                filesA.push_back(it->path().string());
    }
    return filesA;
}

void Resources::addFile(std::filesystem::path path)
{
    std::string name, type;

    std::string fullname = path.filename().string();
    bool isName = true;

    for (size_t i = 0; i < fullname.size(); ++i) 
    {
        if (isName) 
        {
            if (fullname[i] == '.') 
            {
                isName = false;
                continue;
            }
            else 
            {
                name += fullname[i];
                continue;
            }
        }
        type += fullname[i];
    }
    //texture
    if (type == "png" || type == "jpg" || type == "jpeg") 
    {
        auto newTexture = std::make_unique<sf::Texture>();
        newTexture->loadFromFile(path.string());
        newTexture->setSmooth(false);
        texture.insert({ name , move(newTexture) });
    }
    // sound
    if (type == "wav") 
    {
        sf::SoundBuffer buffer;
        sf::Sound sound;

        buffer.loadFromFile(path.string());
        sound.setBuffer(buffer);

        audio.sound.insert({ name, std::pair<sf::SoundBuffer, sf::Sound>(buffer, sound) });
    }
    // music
    if (type == "ogg") 
    {
        auto newMusic = std::make_unique<sf::Music>();
        newMusic->openFromFile(path.string());
        newMusic->setLoop(true);
        audio.music.insert({ name, move(newMusic) });
    }
    // font
    if (type == "ttf" || type == "otf") 
    {
        auto newFont = std::make_unique<sf::Font>();
        newFont->loadFromFile(path.string());
        font.insert({ name , move(newFont) });
    }

    // shaders
    if (type == "vert")
    {
        auto newShader = std::make_unique<sf::Shader>();
        newShader->loadFromFile(path.string(), sf::Shader::Vertex);
        shader.insert({ name, move(newShader) });
    }
    if (type == "frag")
    {
        auto newShader = std::make_unique<sf::Shader>();
        newShader->loadFromFile(path.string(), sf::Shader::Fragment);
        shader.insert({ name, move(newShader) });
    }
}