#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "AssetManager.h"
#include "Globals.h"
#include <random>

enum class Colour
{
	// None is a failsafe
	None = 0,
	Red = 1,
	Blue = 2,
	Green = 3,
	Yellow = 4,
	Purple = 5
};

struct Piece
{
	Colour colour;
	std::string textureName;
	sf::Texture texture;
	sf::Sprite sprite;
};

class CombinedPiece
{
public:
	Piece piece1;
	Piece piece2;

private:
	void LoadSprites();
};

class PieceGenerator
{
public:
	CombinedPiece GenerateRandomPiece(int noColour);

	Colour GetRandomColour(int noColour);
};