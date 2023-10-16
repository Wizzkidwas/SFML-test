#include <sstream>
#include "MovableObject.h"
#include "NonPlayableObject.h"
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

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Holy shit it works");

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
    nonPlayableObjects.push_back(NonPlayableObject("Images/A W A K E N E D.png", 600, 500, 30.0f)); // Speed: 30 pixels per second
    nonPlayableObjects.push_back(NonPlayableObject("Images/Nyck T-Pose.jpg", 200, 0, 50.0f));

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
                    character.move(-5.0f, 0.0f); // Move left
                }
                if (event.key.code == sf::Keyboard::Right)
                {
                    character.move(5.0f, 0.0f); // Move right
                }
                if (event.key.code == sf::Keyboard::Up)
                {
                    character.move(0.0f, -5.0f); // Move up
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    character.move(0.0f, 5.0f); // Move down
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
            nPObject.Update(deltaTime);
        }

        window.clear();
        // Draw all sprites in the collection
        character.draw(window);
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