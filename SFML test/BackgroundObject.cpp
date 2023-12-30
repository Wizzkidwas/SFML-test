#include "BackgroundObject.h"

void BackgroundObject::SetTextureName(std::string texName)
{
	textureName = texName;
}

void BackgroundObject::LoadTexture(AssetManager aM)
{
	texture = aM.GetTexture(textureName);
	sprite.setTexture(texture);
}

void BackgroundObject::SetAndLoadTexture(AssetManager aM, std::string texName)
{
	SetTextureName(texName);
	LoadTexture(aM);
}

void BackgroundObject::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
