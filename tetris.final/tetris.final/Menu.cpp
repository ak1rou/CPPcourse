#include "Menu.h"

Menu::Menu(sf::RenderWindow& window) {
    if (!font.loadFromFile("images\\Stengazeta-Regular_5.ttf")) {
        std::cout << "Error loading font!" << std::endl;
        return;
    }

    text.setFont(font);
    text.setString("PAUSED");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Red);
    text.setPosition(290, 200);

    isButton1Selected = true;
    isButton2Selected = false;
    isButton3Selected = false;
    isButton4Selected = false;
}

void Menu::draw(sf::RenderWindow& window) {
    window.draw(text);

    sf::Vector2f buttonSize(200.0f, 50.0f);
    sf::Vector2f buttonPosition(252.0f, 290.0f);


    float buttonSpacing = 70.0f;

    sf::Font font;
    if (!font.loadFromFile("images\\Stengazeta-Regular_5.ttf")) {
        std::cout << "Error loading font!" << std::endl;
        return;
    }

    sf::Text buttonTexts[4];
    for (int i = 0; i < 4; ++i) {
        buttonTexts[i].setFont(font);
        buttonTexts[i].setCharacterSize(25);
        buttonTexts[i].setFillColor(sf::Color::Black);
    }

    buttonTexts[0].setString("RESUME");
    buttonTexts[1].setString("NEW GAME");
    buttonTexts[2].setString("MUTE SOUND");
    buttonTexts[3].setString("EXIT");

    for (int i = 0; i < 4; ++i) {
        sf::FloatRect textRect = buttonTexts[i].getLocalBounds();
        buttonTexts[i].setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        buttonTexts[i].setPosition(buttonPosition.x + buttonSize.x / 2.0f, buttonPosition.y + buttonSize.y / 2.0f);

        sf::RectangleShape button(buttonSize);
        button.setPosition(buttonPosition);
        button.setFillColor(sf::Color::White);
        button.setOutlineThickness(5);
        button.setOutlineColor(sf::Color::Black);

        if (i == 0 && isButton1Selected)
            button.setFillColor(sf::Color::Red);
        else if (i == 1 && isButton2Selected)
            button.setFillColor(sf::Color::Red);
        else if (i == 2 && isButton3Selected)
            button.setFillColor(sf::Color::Red);
        else if (i == 3 && isButton4Selected)
            button.setFillColor(sf::Color::Red);

        window.draw(button);
        window.draw(buttonTexts[i]);

        buttonPosition.y += buttonSpacing;
    }
}

void Menu::moveUp() {
    if (isButton1Selected) {
        isButton1Selected = false;
        isButton4Selected = true;
    }
    else if (isButton2Selected) {
        isButton2Selected = false;
        isButton1Selected = true;
    }
    else if (isButton3Selected) {
        isButton3Selected = false;
        isButton2Selected = true;
    }
    else if (isButton4Selected) {
        isButton4Selected = false;
        isButton3Selected = true;
    }
}

void Menu::moveDown() {
    if (isButton1Selected) {
        isButton1Selected = false;
        isButton2Selected = true;
    }
    else if (isButton2Selected) {
        isButton2Selected = false;
        isButton3Selected = true;
    }
    else if (isButton3Selected) {
        isButton3Selected = false;
        isButton4Selected = true;
    }
    else if (isButton4Selected) {
        isButton4Selected = false;
        isButton1Selected = true;
    }
}

int Menu::getPressedItem() const {
    if (isButton1Selected)
        return 1;
    else if (isButton2Selected)
        return 2;
    else if (isButton3Selected)
        return 3;
    else if (isButton4Selected)
        return 4;
    return -1;
}
