#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"

class StartMenu 
{
public:
    StartMenu(sf::RenderWindow& window);
    void handleEvents(sf::Event& event);
    void render();

    bool isMenuClosed() const;

private:
    sf::RenderWindow& m_window;
    sf::Text m_startText;
    bool m_menuClosed;
};

class Menu 
{
public:
    Menu(sf::RenderWindow& window);
    void handleEvents(sf::Event& event);
    void render();

    void moveUp();
    void moveDown();
    int getPressedItem() const;

private:
    sf::RenderWindow& m_window;
    sf::Text m_text;
    bool m_isButton1Selected;
    bool m_isButton2Selected;
    bool m_isButton3Selected;
    bool m_isButton4Selected;
};

class EndMenu
{
public:
    EndMenu(sf::RenderWindow& window);
    void handleEvents(sf::Event& event);
    void render();
    void moveUp();
    void moveDown();
    int getPressedItem() const;

private:
    sf::RenderWindow& m_window;
    sf::Text m_text;
    bool m_isButton1Selected;
    bool m_isButton2Selected;
    bool m_isButton3Selected;
};