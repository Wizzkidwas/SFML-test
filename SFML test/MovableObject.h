#pragma once
#include <sstream>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
using std::string;

class MovableObject
{
private:
    std::string textureName;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    MovableObject(std::string texName, float x, float y)
    {
        textureName = texName;
        sprite.setPosition(x, y);
    }

    void SetTextureName(std::string texName);

    void LoadTexture(AssetManager aM);

    void SetAndLoadTexture(AssetManager aM, std::string texName);

    void Move(float offsetX, float offsetY);

    void Draw(sf::RenderWindow& window);
};