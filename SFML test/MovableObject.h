#pragma once
#include <sstream>
#include <SFML/Graphics.hpp>
using std::string;

class MovableObject
{
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    MovableObject(const std::string& textureFile, float x, float y)
    {
        if (!texture.loadFromFile(textureFile))
        {
            // Handle error if the texture couldn't be loaded
        }
        sprite.setTexture(texture);
        sprite.setPosition(x, y);
    }

    void move(float offsetX, float offsetY)
    {
        sprite.move(offsetX, offsetY);
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(sprite);
    }
};