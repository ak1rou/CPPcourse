#include "ResourceInitializer.h"

void ResourceInitializer::initializeResources(sf::RenderWindow& window, sf::Font& font, sf::SoundBuffer& themeBuffer, 
    sf::SoundBuffer& gameoverBuffer, sf::SoundBuffer& leveldestroyedBuffer, sf::Sound& themeSound, sf::Sound& gameoverSound,
    sf::Sound& leveldestroyedSound, sf::Text& destroyedLevelsCount, sf::Text& startGameText, sf::Text& nextTetraminoText, 
    sf::Text& escapeText, sf::Texture& texture, sf::Texture& texture_background, sf::Texture& texture_playingField, 
    sf::Sprite& sprite, sf::Sprite& sprite_background, sf::Sprite& sprite_field)
{
    window.create(sf::VideoMode(720, 960), "TETRIS");

    if (!font.loadFromFile("images\\Stengazeta-Regular_5.ttf")) {
        std::cout << "Error loading font!" << std::endl;
    }

    if (!themeBuffer.loadFromFile("images\\theme.mp3")) {
        std::cout << "error loading theme.mp3";
    }

    if (!gameoverBuffer.loadFromFile("images\\gameover.mp3")) {
        std::cout << "error loading gameover.mp3";
    }

    if (!leveldestroyedBuffer.loadFromFile("images\\leveldestroyed.mp3")) {
        std::cout << "error loading leveldestroyed.mp3";
    }

    themeSound.setBuffer(themeBuffer);
    gameoverSound.setBuffer(gameoverBuffer);
    leveldestroyedSound.setBuffer(leveldestroyedBuffer);

    destroyedLevelsCount.setFont(font);
    destroyedLevelsCount.setCharacterSize(40);
    destroyedLevelsCount.setFillColor(sf::Color::Magenta);
    destroyedLevelsCount.setPosition(470, 350);
    destroyedLevelsCount.setOutlineThickness(5);
    destroyedLevelsCount.setOutlineColor(sf::Color::White);
    destroyedLevelsCount.setOrigin(destroyedLevelsCount.getGlobalBounds().width / 2, 0);

    startGameText.setFont(font);
    startGameText.setString("PRESS ENTER TO START THE GAME");
    startGameText.setCharacterSize(45);
    startGameText.setFillColor(sf::Color::Red);
    startGameText.setPosition(110, 400);

    nextTetraminoText.setFont(font);
    nextTetraminoText.setString("NEXT TETRAMINO");
    nextTetraminoText.setCharacterSize(40);
    nextTetraminoText.setFillColor(sf::Color::Magenta);
    nextTetraminoText.setPosition(475, 50);
    nextTetraminoText.setOutlineThickness(5);
    nextTetraminoText.setOutlineColor(sf::Color::White);

    escapeText.setFont(font);
    escapeText.setString("ESCAPE FOR PAUSE");
    escapeText.setCharacterSize(30);
    escapeText.setFillColor(sf::Color::Magenta);
    escapeText.setPosition(135, 7);
    escapeText.setOutlineThickness(2);
    escapeText.setOutlineColor(sf::Color::White);

    texture.loadFromFile("images\\tiles.png");
    texture_background.loadFromFile("images\\background.png");
    texture_playingField.loadFromFile("images\\playingField.png");

    sprite.setTexture(texture);
    sprite_background.setTexture(texture_background);
    sprite_field.setTexture(texture_playingField);
}
