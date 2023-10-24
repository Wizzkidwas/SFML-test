#include "TextDisplay.h"

void TextDisplay::SetText(const std::string& newText)
{
    text.setString(newText);
}

void TextDisplay::SetPosition(float x, float y)
{
    text.setPosition(x, y);
}

void TextDisplay::Draw(sf::RenderWindow& window)
{
    window.draw(text);
}