#pragma once
#include <map>
#include <sstream>
#include <SFML/Graphics.hpp>

class AssetManager
{
private:
    std::map<std::string, sf::Texture> textures;

public:
    void LoadTexture(const std::string& name, const std::string& filename);
    
    sf::Texture& GetTexture(const std::string& name);
};

