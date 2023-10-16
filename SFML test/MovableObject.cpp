#include "MovableObject.h"

void MovableObject::Move(float offsetX, float offsetY)
{
    sprite.move(offsetX, offsetY);
}

void MovableObject::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}