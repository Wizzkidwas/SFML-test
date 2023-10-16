#pragma once
#include <map>
#include <sstream>
#include <SFML/Graphics.hpp>

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
    void loadFont(const std::string& name, const std::string& filename);
    sf::Font& getFont(const std::string& name);

    // Load and get methods for sounds
    void loadSoundBuffer(const std::string& name, const std::string& filename);
    sf::SoundBuffer& getSoundBuffer(const std::string& name);

    // Load and get methods for music
    void loadMusic(const std::string& name, const std::string& filename);
    sf::Music& getMusic(const std::string& name);
};

