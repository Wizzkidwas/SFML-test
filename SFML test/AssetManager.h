#pragma once
#include <map>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

class AssetManager
{
private:
    std::map<std::string, sf::Texture> textures;
    std::map<std::string, sf::Font> fonts;
    std::map<std::string, sf::SoundBuffer> soundBuffers;
    std::map<std::string, sf::Music> music;

public:
    // Load and get methods for textures
    void LoadTexture(const std::string& name, const std::string& filename);
    sf::Texture& GetTexture(const std::string& name);

    // Load and get methods for fonts
    void LoadFont(const std::string& name, const std::string& filename);
    sf::Font& GetFont(const std::string& name);

    // Load and get methods for sounds
    void LoadSoundBuffer(const std::string& name, const std::string& filename);
    sf::SoundBuffer& GetSoundBuffer(const std::string& name);

    // Load and get methods for music
    void LoadMusic(const std::string& name, const std::string& filename);
    sf::Music& GetMusic(const std::string& name);
};

