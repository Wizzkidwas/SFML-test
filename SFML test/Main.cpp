#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Holy shit it works");

    // Load the image
    sf::Texture texture1, texture2;
    if (!texture1.loadFromFile("Images/When you're the normal one.png") || !texture2.loadFromFile("Images/A W A K E N E D.png"))
    {
        // Handle the case where the image couldn't be loaded
        return -1;
    }

    sf::Sprite sprite1(texture1);
    sf::Sprite sprite2(texture2);

    // Set the initial position of the sprite
    sf::Vector2f sprite1Position(400, 300);
    sprite1.setPosition(sprite1Position);
    sprite2.setPosition(600, 500);

    // Put sprites into a vector
    std::vector<sf::Sprite> sprites;
    sprites.push_back(sprite1);
    sprites.push_back(sprite2);

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
                    sprite1Position.x -= 5; // Move left
                }
                if (event.key.code == sf::Keyboard::Right)
                {
                    sprite1Position.x += 5; // Move right
                }
                if (event.key.code == sf::Keyboard::Up)
                {
                    sprite1Position.y -= 5; // Move up
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    sprite1Position.y += 5; // Move down
                }
                sprites.front().setPosition(sprite1Position);
                break;

            // we don't process other types of events
            default:
                break;
            }
        }

        window.clear();
        // Draw all sprites in the collection
        for (const auto& sprite : sprites)
        {
            window.draw(sprite);
        }
        window.display();
    }

    return 0;
}
