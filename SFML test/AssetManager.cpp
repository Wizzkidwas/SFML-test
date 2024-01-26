#include "AssetManager.h"
#include <iostream>

void AssetManager::InitialiseTextures()
{
    LoadTexture("Background", "Images/Backgrounds/Default/PlayerField.png");
    LoadTexture("Vettel", "Images/A W A K E N E D.png");
    LoadTexture("Nyck", "Images/Nyck T-Pose.jpg");
    LoadTexture("Rafisol", "Images/RafisolPreBattle.png");
}

void AssetManager::InitialiseText()
{
    LoadFont("defaultFont", "Fonts/Mikado Medium.otf");
    LoadFont("meme", "Fonts/impact.ttf");
}

void AssetManager::InitialiseCustomPieces(std::string folder)
{
    std::string fileFolder = "Images/Skins/" + folder;
    LoadTexture("Red", folder + "/red.png");
    LoadTexture("Blue", folder + "/blue.png");
    LoadTexture("Green", folder + "/green.png");
    LoadTexture("Yellow", folder + "/yellow.png");
    LoadTexture("Purple", folder + "/purple.png");
}


void AssetManager::LoadTexture(const std::string& name, const std::string& filename)
{
    sf::Texture texture;
    if (texture.loadFromFile(filename))
    {
        textures[name] = texture;
    }
    else
    {
        texture.loadFromFile("Images/Fail.png");
        // Handle the case where the texture couldn't be loaded (Might set a default texture lol)
    }
}

sf::Texture& AssetManager::GetTexture(const std::string& name)
{
    if (textures.find(name) != textures.end())
    {
        std::cout << "Texture | " << name << " | snatched" << std::endl;
        return textures[name];
    }
    else
    {
        // Handle the case where the texture is not found
        // Here, we return an empty (uninitialized) texture.
        static sf::Texture failTexture;
        failTexture.loadFromFile("Images/Fail.png");
        return failTexture;
    }
}

void AssetManager::LoadFont(const std::string& name, const std::string& filename)
{
    sf::Font font;
    if (font.loadFromFile(filename))
    {
        fonts[name] = font;
    }
    else
    {
        // Handle font loading error.
    }
}

sf::Font& AssetManager::GetFont(const std::string& name)
{
    if (fonts.find(name) != fonts.end())
    {
        return fonts[name];
    }
    else
    {
        // Handle font not found (e.g., return a default font or throw an exception).
        // Here, we return a default font.
        static sf::Font defaultFont;
        return defaultFont;
    }
}

void AssetManager::LoadSoundBuffer(const std::string& name, const std::string& filename)
{
    sf::SoundBuffer soundBuffer;
    if (soundBuffer.loadFromFile(filename))
    {
        soundBuffers[name] = soundBuffer;
    }
    else
    {
        // Handle sound buffer loading error.
    }
}

sf::SoundBuffer& AssetManager::GetSoundBuffer(const std::string& name)
{
    if (soundBuffers.find(name) != soundBuffers.end())
    {
        return soundBuffers[name];
    }
    else 
    {
        // Handle sound buffer not found (e.g., return a default sound buffer or throw an exception).
        // Here, we return a default sound buffer.
        static sf::SoundBuffer defaultSoundBuffer;
        return defaultSoundBuffer;
    }
}