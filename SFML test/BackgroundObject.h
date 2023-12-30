#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>
#include "AssetManager.h"

class BackgroundObject
{
private:
    std::string textureName;
    sf::Texture texture;
    sf::Sprite sprite;
    
public:

    BackgroundObject(std::string texName, float x, float y)
    {
        textureName = texName;
        sprite.setPosition(x, y);
    }

    void SetTextureName(std::string texName);

    void LoadTexture(AssetManager aM);

    void SetAndLoadTexture(AssetManager aM, std::string texName);

    void Draw(sf::RenderWindow& window);
};

