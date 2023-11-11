#include "TextDisplay.h"

void TextDisplay::SetText(const std::string& newText)
{
    text.setString(newText);
}

void TextDisplay::SetPosition(float x, float y)
{
    text.setPosition(x, y);
}

void TextDisplay::ToggleText()
{
    showText = !showText;
}

void TextDisplay::Draw(sf::RenderWindow& window)
{
    if (showText)
    {
        window.draw(text);
    }
}