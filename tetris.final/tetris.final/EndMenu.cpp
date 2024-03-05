#include "EndMenu.h"

EndMenu::EndMenu(sf::RenderWindow& window) {
    if (!font.loadFromFile("images\\Stengazeta-Regular_5.ttf")) {
        std::cout << "Error loading font!" << std::endl;
        return;
    }

    text.setFont(font);
    text.setString("GAME OVER");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Red);
    text.setPosition(165, 200);

    isButton1Selected = true;
    isButton2Selected = false;
}

void EndMenu::draw(sf::RenderWindow& window) {
    window.draw(text);

    sf::Vector2f buttonSize(200.0f, 50.0f);
    sf::Vector2f buttonPosition(238.0f, 350.0f);
    float buttonSpacing = 70.0f;

    sf::Font font;
    if (!font.loadFromFile("images\\Stengazeta-Regular_5.ttf")) {
        std::cout << "Error loading font!" << std::endl;
        return;
    }

    sf::Text buttonTexts[2];
    for (int i = 0; i < 2; ++i) {
        buttonTexts[i].setFont(font);
        buttonTexts[i].setCharacterSize(25);
        buttonTexts[i].setFillColor(sf::Color::Black);
    }

    buttonTexts[0].setString("NEW GAME");
    buttonTexts[1].setString("EXIT");

    for (int i = 0; i < 2; ++i) {
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

        window.draw(button);
        window.draw(buttonTexts[i]);

        buttonPosition.y += buttonSpacing;
    }
}

void EndMenu::moveUp() {
    if (isButton1Selected) {
        isButton1Selected = false;
        isButton2Selected = true;
    }
    else if (isButton2Selected) {
        isButton2Selected = false;
        isButton1Selected = true;
    }
}

void EndMenu::moveDown() {
    if (isButton1Selected) {
        isButton1Selected = false;
        isButton2Selected = true;
    }
    else if (isButton2Selected) {
        isButton2Selected = false;
        isButton1Selected = true;
    }
}

int EndMenu::getPressedItem() const {
    if (isButton1Selected)
        return 1;
    else if (isButton2Selected)
        return 2;
    return -1;
}
