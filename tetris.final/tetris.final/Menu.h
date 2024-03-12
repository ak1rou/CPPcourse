#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Menu {
public:
    Menu(sf::RenderWindow& window);

    void draw(sf::RenderWindow& window);
    void moveUp();
    void moveDown();
    int getPressedItem() const;

private:
    sf::Font font;
    sf::Text text;
    bool isButton1Selected, isButton2Selected, isButton3Selected, isButton4Selected;
};
