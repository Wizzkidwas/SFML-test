#include <sstream>
#include "MovableObject.h"
#include "NonPlayableObject.h"
#include "AssetManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Time.hpp>

enum class GameState
{
    Startup = 0,
    MainMenu = 1,
    Gameplay = 2,
    PauseMenu = 3,
    Dialogue = 4
};

void PushToVector(std::vector<NonPlayableObject>& vec, AssetManager& aM, std::string texName, float x, float y, float s);
void PushToVector(std::vector<NonPlayableObject>& vec, AssetManager& aM, std::string texName, float x, float y, float s, Type t);

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Holy shit it works");

    AssetManager assetManager;
    // Load textures using the asset manager, all textures stored in this function
    assetManager.InitialiseTextures();

    // TODO: Shift music and sounds to asset manager
    // TODO: Add text

    // Create music variable and load music
    sf::Music music;
    if (!music.openFromFile("Audio/Music/BGM_ALL_DLCBGM_V40_heppoko2.WAV"))
    {
        return -1; // Error: Music failed to load
    }
    music.setLoop(true);
    music.play();

    // Create a sound buffer and load a sound effect file
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("Audio/SFX/V_RSL_09.wav"))
    {
        return -1; // Error loading the sound effect file
    }

    // Create a sound object and set its buffer
    sf::Sound sound;
    sound.setBuffer(buffer);

    // Load the player character
    MovableObject character("Images/When you're the normal one.png", 400, 300);

    // Load and place non-playable objects into a vector
    std::vector<NonPlayableObject> nonPlayableObjects;
    PushToVector(nonPlayableObjects, assetManager, "Nyck", 200, 0, 50.0f);
    PushToVector(nonPlayableObjects, assetManager, "Vettel", 600, 500, 30.0f);
    PushToVector(nonPlayableObjects, assetManager, "Rafisol", 800, 0, 30.0f, Type::Immobile);

    // Loads textures after being placed into vector which prevents texture pointers from breaking
    // NOTE: Will need to run this again when adding a new item to this vector as memory locations will change
    
    for (auto& nPObject : nonPlayableObjects)
    {
        nPObject.LoadTexture(assetManager);
    }

    window.setFramerateLimit(60); // SFML handles frame rate limits by itself
    GameState gameState = GameState::Startup;   // Soon to be used for funky menus
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            // window closed
            case sf::Event::Closed:
                window.close();
                break;

                // key pressed
            case sf::Event::KeyPressed:
                // Handle arrow key presses to move the sprite
                if (event.key.code == sf::Keyboard::Left)
                {
                    character.Move(-5.0f, 0.0f); // Move left
                }
                if (event.key.code == sf::Keyboard::Right)
                {
                    character.Move(5.0f, 0.0f); // Move right
                }
                if (event.key.code == sf::Keyboard::Up)
                {
                    character.Move(0.0f, -5.0f); // Move up
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    character.Move(0.0f, 5.0f); // Move down
                }

                // Plays sound effect when space is pressed
                if (event.key.code == sf::Keyboard::Space)
                {
                    sound.play();
                }

                if (event.key.code == sf::Keyboard::Home)
                {
                    sf::SoundSource::Status musicStatus = music.getStatus();
                    if (musicStatus == sf::SoundSource::Status::Playing)
                    {
                        music.pause();
                    }
                    else if (musicStatus == sf::SoundSource::Status::Paused)
                    {
                        music.play();
                    }
                }
                break;

            // we don't process other types of events
            default:
                break;
            }
        }

        sf::Time deltaTime = clock.restart(); // Get time elapsed since the last frame
        for (auto& nPObject : nonPlayableObjects)
        {
            // Update the non-playable object's position
            // nPObject.LoadTexture(assetManager);
            nPObject.Update(deltaTime);
        }

        window.clear();
        // Draw all sprites in the collection
        character.Draw(window);
        for (auto& nPObject : nonPlayableObjects)
        {
            nPObject.Draw(window);
        }
        window.display();
    }
    music.stop();
    sound.stop();
    return 0;
}

void PushToVector(std::vector<NonPlayableObject> &vec, AssetManager &aM, std::string texName, float x, float y, float s)
{
    NonPlayableObject nPO = NonPlayableObject(texName, x, y, s);
    vec.push_back(nPO);
    vec.back().LoadTexture(aM);
}

void PushToVector(std::vector<NonPlayableObject>& vec, AssetManager& aM, std::string texName, float x, float y, float s, Type t)
{
    NonPlayableObject nPO = NonPlayableObject(texName, x, y, s, t);
    vec.push_back(nPO);
    vec.back().LoadTexture(aM);
}