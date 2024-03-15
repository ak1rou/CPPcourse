#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 960), "Brick Breaker");

    Resources::loadTextures();
    Resources::loadFonts();

    StartMenu startMenu(window);

    while (window.isOpen())
    {
        if (!startMenu.isMenuClosed())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                startMenu.handleEvents(event);
            }
            startMenu.render();
        }
        else
        {
            Game game(window);
            game.run();
        }
    }

    return 0;
}
