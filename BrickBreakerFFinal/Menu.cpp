#include "Menu.h"
#include "Game.h"

StartMenu::StartMenu(sf::RenderWindow& window) : m_window(window), m_menuClosed(false) 
{
    m_startText.setFont(Resources::getFont("font"));
    m_startText.setString("PRESS ENTER TO START");
    m_startText.setCharacterSize(82);
    m_startText.setFillColor(sf::Color::Black);
    m_startText.setOutlineColor(sf::Color::White);
    m_startText.setOutlineThickness(5);
    

    sf::FloatRect textBounds = m_startText.getLocalBounds();
    m_startText.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
    m_startText.setPosition(window.getSize().x / static_cast<float>(2), window.getSize().y / static_cast<float>(2));
}

void StartMenu::handleEvents(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) 
    {
        m_menuClosed = true; 
    }
}

void StartMenu::render() 
{
    m_window.clear();

    sf::Sprite background(Resources::getTexture("background"));
    m_window.draw(background);

    m_window.draw(m_startText);

    m_window.display();
}

bool StartMenu::isMenuClosed() const
{
    return m_menuClosed;
}

Menu::Menu(sf::RenderWindow& window) : m_window(window), m_isButton1Selected(true), m_isButton2Selected(false), m_isButton3Selected(false), m_isButton4Selected(false)
{
    Resources::loadFonts();
    m_text.setFont(Resources::getFont("font"));
    m_text.setString("PAUSED");
    m_text.setCharacterSize(64);
    m_text.setFillColor(sf::Color::Red);
    m_text.setPosition(273, 200);
    m_text.setOutlineColor(sf::Color::White);
    m_text.setOutlineThickness(3);
}

void Menu::handleEvents(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed) 
    {
        if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) 
        {
            moveUp();
        }
        else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
        {
            moveDown();
        }
    }
}

void Menu::render() 
{
    m_window.draw(m_text);

    sf::Vector2f buttonSize(200.0f, 50.0f);
    sf::Vector2f buttonPosition(252.0f, 290.0f);
    float buttonSpacing = 70.0f;

    sf::Text buttonTexts[4];
    for (int i = 0; i < 4; ++i) {
        buttonTexts[i].setFont(Resources::getFont("font"));
        buttonTexts[i].setCharacterSize(25);
        buttonTexts[i].setFillColor(sf::Color::Black);
    }

    buttonTexts[0].setString("RESUME");
    buttonTexts[1].setString("NEW GAME");
    buttonTexts[2].setString("TOGGLE VOLUME");
    buttonTexts[3].setString("EXIT");

    for (int i = 0; i < 4; ++i) {
        sf::FloatRect textRect = buttonTexts[i].getLocalBounds();
        buttonTexts[i].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        buttonTexts[i].setPosition(buttonPosition.x + buttonSize.x / 2.0f, buttonPosition.y + buttonSize.y / 2.0f);

        sf::RectangleShape button(buttonSize);
        button.setPosition(buttonPosition);
        button.setFillColor(sf::Color::White);
        button.setOutlineThickness(5);
        button.setOutlineColor(sf::Color::Red);

        if (i == 0 && m_isButton1Selected)
            button.setFillColor(sf::Color::Red);
        else if (i == 1 && m_isButton2Selected)
            button.setFillColor(sf::Color::Red);
        else if (i == 2 && m_isButton3Selected)
            button.setFillColor(sf::Color::Red);
        else if (i == 3 && m_isButton4Selected)
            button.setFillColor(sf::Color::Red);

        m_window.draw(button);
        m_window.draw(buttonTexts[i]);

        buttonPosition.y += buttonSpacing;
    }
}

void Menu::moveUp() {
    if (m_isButton1Selected) {
        m_isButton1Selected = false;
        m_isButton4Selected = true;
    }
    else if (m_isButton2Selected) {
        m_isButton2Selected = false;
        m_isButton1Selected = true;
    }
    else if (m_isButton3Selected) {
        m_isButton3Selected = false;
        m_isButton2Selected = true;
    }
    else if (m_isButton4Selected) {
        m_isButton4Selected = false;
        m_isButton3Selected = true;
    }
}

void Menu::moveDown() {
    if (m_isButton1Selected) {
        m_isButton1Selected = false;
        m_isButton2Selected = true;
    }
    else if (m_isButton2Selected) {
        m_isButton2Selected = false;
        m_isButton3Selected = true;
    }
    else if (m_isButton3Selected) {
        m_isButton3Selected = false;
        m_isButton4Selected = true;
    }
    else if (m_isButton4Selected) {
        m_isButton4Selected = false;
        m_isButton1Selected = true;
    }
}

int Menu::getPressedItem() const {
    if (m_isButton1Selected)
        return 1;
    else if (m_isButton2Selected)
        return 2;
    else if (m_isButton3Selected)
        return 3;
    else if (m_isButton4Selected)
        return 4;
    return -1;
}

EndMenu::EndMenu(sf::RenderWindow& window) : m_window(window), m_isButton1Selected(true), m_isButton2Selected(false), m_isButton3Selected(false)
{
    Resources::loadFonts();
    m_text.setFont(Resources::getFont("font"));
    m_text.setString("GAME OVER!"); 
    m_text.setCharacterSize(100);
    m_text.setFillColor(sf::Color::Red);
    m_text.setPosition(170, 180);
    m_text.setOutlineColor(sf::Color::White);
    m_text.setOutlineThickness(5);
}

void EndMenu::handleEvents(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
        {
            moveUp();
        }
        else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
        {
            moveDown();
        }
    }
}

void EndMenu::render()
{
    m_window.clear();
    m_window.draw(m_text);

    sf::Vector2f buttonSize(200.0f, 50.0f);
    sf::Vector2f buttonPosition(252.0f, 320.0f);
    float buttonSpacing = 70.0f;

    sf::Text buttonTexts[3];
    for (int i = 0; i < 3; ++i) {
        buttonTexts[i].setFont(Resources::getFont("font"));
        buttonTexts[i].setCharacterSize(25);
        buttonTexts[i].setFillColor(sf::Color::Black);
    }

    buttonTexts[0].setString("NEW GAME");
    buttonTexts[1].setString("TOGGLE VOLUME");
    buttonTexts[2].setString("EXIT");

    for (int i = 0; i < 3; ++i) {
        sf::FloatRect textRect = buttonTexts[i].getLocalBounds();
        buttonTexts[i].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        buttonTexts[i].setPosition(buttonPosition.x + buttonSize.x / 2.0f, buttonPosition.y + buttonSize.y / 2.0f);

        sf::RectangleShape button(buttonSize);
        button.setPosition(buttonPosition);
        button.setFillColor(sf::Color::White);
        button.setOutlineThickness(5);
        button.setOutlineColor(sf::Color::Black);

        if (i == 0 && m_isButton1Selected)
            button.setFillColor(sf::Color::Red);
        else if (i == 1 && m_isButton2Selected)
            button.setFillColor(sf::Color::Red);
        else if (i == 2 && m_isButton3Selected)
            button.setFillColor(sf::Color::Red);

        m_window.draw(button);
        m_window.draw(buttonTexts[i]);

        buttonPosition.y += buttonSpacing;
    }
}

void EndMenu::moveUp() {
    if (m_isButton1Selected) {
        m_isButton1Selected = false;
        m_isButton3Selected = true;
    }
    else if (m_isButton2Selected) {
        m_isButton2Selected = false;
        m_isButton1Selected = true;
    }
    else if (m_isButton3Selected) {
        m_isButton3Selected = false;
        m_isButton2Selected = true;
    }
}

void EndMenu::moveDown() {
    if (m_isButton1Selected) {
        m_isButton1Selected = false;
        m_isButton2Selected = true;
    }
    else if (m_isButton2Selected) {
        m_isButton2Selected = false;
        m_isButton3Selected = true;
    }
    else if (m_isButton3Selected) {
        m_isButton3Selected = false;
        m_isButton1Selected = true;
    }
}

int EndMenu::getPressedItem() const {
    if (m_isButton1Selected)
        return 1;
    else if (m_isButton2Selected)
        return 2;
    else if (m_isButton3Selected)
        return 3;
    return -1;
}