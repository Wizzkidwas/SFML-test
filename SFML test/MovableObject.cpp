#include "MovableObject.h"

void MovableObject::SetTextureName(std::string texName)
{
    textureName = texName;
}

void MovableObject::LoadTexture(AssetManager aM)
{
    texture = aM.GetTexture(textureName);
    sprite.setTexture(texture);
}

void MovableObject::SetAndLoadTexture(AssetManager aM, std::string texName)
{
    SetTextureName(texName);
    LoadTexture(aM);
}
void MovableObject::Move(float offsetX, float offsetY)
{
    sprite.move(offsetX, offsetY);
}

void MovableObject::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}