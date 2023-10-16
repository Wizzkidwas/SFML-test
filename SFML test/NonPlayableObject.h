#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>

// Sets direction for object to move in, numbered for RNG purposes
enum class Direction
{
    Up = 0,
    Down = 1,
    Left = 2,
    Right = 3
};

class NonPlayableObject
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    float speed; // Speed of movement in pixels per second
    Direction direction = Direction::Up;

public:
    NonPlayableObject(const std::string& textureFile, float x, float y, float s)
    {
        speed = s;
        if (!texture.loadFromFile(textureFile))
        {
            std::cout << "Woah this file | " << textureFile << " | didn't load!" << std::endl;
            // Handle error if the texture couldn't be loaded
        }

        sprite.setTexture(texture);
        std::cout << "Woah this file | " << textureFile << " | did load!" << std::endl;
        sprite.setPosition(x, y);
    }

    void Update(sf::Time deltaTime);

    void Draw(sf::RenderWindow& window);

    void ChangeDirection();
};