#include "NonPlayableObject.h"
#include <random>

void NonPlayableObject::SetTextureName(std::string texName)
{
    textureName = texName;
}

void NonPlayableObject::LoadTexture(AssetManager aM)
{
    texture = aM.GetTexture(textureName);
    sprite.setTexture(texture);
}

void NonPlayableObject::SetAndLoadTexture(AssetManager aM, std::string texName)
{
    SetTextureName(texName);
    LoadTexture(aM);
}

void NonPlayableObject::Update(sf::Time deltaTime)
{
    // No use doing movement for immobile objects
    if (type == Type::Movable)
    {
        // Move the object based on its speed and time
        float moveAmount = speed * deltaTime.asSeconds();

        // 10% chance to change direction
        ChangeDirection();

        switch (direction)
        {
        case Direction::Up:
            sprite.move(0.0f, -moveAmount); // Move up
            break;
        case Direction::Down:
            sprite.move(0.0f, moveAmount); // Move down
            break;
        case Direction::Left:
            sprite.move(moveAmount, 0.0f); // Move left
            break;
        case Direction::Right:
            sprite.move(-moveAmount, 0.0f); // Move right
            break;
        default:
            break;
        }
    }

}

void NonPlayableObject::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void NonPlayableObject::ChangeDirection()
{
    // Initialises RNG
    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister RNG
    int directionChangeChance = 20;
    std::uniform_int_distribution<int> distribution(1, directionChangeChance); // Range: [1, 20]

    // Generate a random number
    int randomNumber = distribution(gen);

    // 10% chance to change direction
    if (randomNumber == directionChangeChance)
    {
        // Generates another random number
        std::uniform_int_distribution<int> directionChoice(1, 4); // Range [1, 4]
        int randomDirection;
        // Prevents RNG from choosing the same direction
        do
        {
            randomDirection = directionChoice(gen);
        } while (randomDirection == (int)direction);
        
        // Sets direction to corresponding number (See Direction class in header)
        direction = (Direction)randomDirection;
    }
}

void NonPlayableObject::ChangeType()
{
    switch (type)
    {
    case Type::Movable:
        type = Type::Immobile;
        break;
    case Type::Immobile:
        type = Type::Movable;
        break;
    default:
        break;
    }
}
