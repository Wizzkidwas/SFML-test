#include "AssetManager.h"
#include <iostream>
void AssetManager::LoadTexture(const std::string& name, const std::string& filename)
{
    sf::Texture texture;
    if (texture.loadFromFile(filename))
    {
        textures[name] = texture;
    }
    else
    {
        texture.loadFromFile("Images/Fail.png");
        // Handle the case where the texture couldn't be loaded (Might set a default texture lol)
    }
}

sf::Texture& AssetManager::GetTexture(const std::string& name)
{
    if (textures.find(name) != textures.end())
    {
        std::cout << "Texture | " << name << " | snatched" << std::endl;
        return textures[name];
    }
    else
    {
        // Handle the case where the texture is not found
        // Here, we return an empty (uninitialized) texture.
        static sf::Texture failTexture;
        failTexture.loadFromFile("Images/Fail.png");
        return failTexture;
    }
}
