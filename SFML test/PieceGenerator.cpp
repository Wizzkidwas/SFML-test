#include "PieceGenerator.h"

CombinedPiece PieceGenerator::GenerateRandomPiece(int noColour)
{
	CombinedPiece newPiece;
	newPiece.piece1.colour = GetRandomColour(noColour);
	newPiece.piece2.colour = GetRandomColour(noColour);
	
	return newPiece;
}

Colour PieceGenerator::GetRandomColour(int noColour)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, noColour);
	int pieceColour = distribution(generator);

	if (pieceColour < 1 || pieceColour > 5)
	{
		return (Colour)0;
	}
	else
	{
		return (Colour)pieceColour;
	}
}

void CombinedPiece::LoadSprites()
{
	
	piece1.colour;
}
