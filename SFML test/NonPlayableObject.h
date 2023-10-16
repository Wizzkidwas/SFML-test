#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>
#include "AssetManager.h"

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
    std::string textureName;
    sf::Texture texture;
    sf::Sprite sprite;
    float speed; // Speed of movement in pixels per second
    Direction direction = Direction::Up;

public:

    NonPlayableObject(std::string texName, float x, float y, float s)
    {
        textureName = texName;
        speed = s;
        sprite.setPosition(x, y);
    }

    void SetTextureName(std::string texName);

    void LoadTexture(AssetManager aM);

    void SetAndLoadTexture(AssetManager aM, std::string texName);

    void Update(sf::Time deltaTime);

    void Draw(sf::RenderWindow& window);

    void ChangeDirection();
};