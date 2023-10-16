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
            texture.loadFromFile("Images/Fail.png");
            // Handle error if the texture couldn't be loaded
        }
        sprite.setTexture(texture);
        sprite.setPosition(x, y);
    }

    void Move(float offsetX, float offsetY);

    void Draw(sf::RenderWindow& window);
};