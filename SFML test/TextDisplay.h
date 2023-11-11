#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include "AssetManager.h"

class TextDisplay
{
private:
    sf::Text text;
    bool showText;

public:
    TextDisplay(AssetManager& assetManager, const std::string& fontName, const std::string& word, unsigned int characterSize, sf::Color colour, float x, float y)
    {
        text.setFont(assetManager.GetFont(fontName));
        text.setString(word);
        text.setCharacterSize(characterSize);
        text.setFillColor(colour);
        text.setPosition(x, y);
        showText = true;
    }

    void SetText(const std::string& text);
    void SetPosition(float x, float y);
    void ToggleText();
    void Draw(sf::RenderWindow& window);
};