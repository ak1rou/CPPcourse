#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class ResourceInitializer {
public:
    static void initializeResources(sf::RenderWindow& window, sf::Font& font, sf::SoundBuffer& themeBuffer, 
        sf::SoundBuffer& gameoverBuffer, sf::SoundBuffer& leveldestroyedBuffer, sf::Sound& themeSound, 
        sf::Sound& gameoverSound, sf::Sound& leveldestroyedSound, sf::Text& destroyedLevelsCount, sf::Text& startGameText,
        sf::Text& nextTetraminoText, sf::Text& escapeText, sf::Texture& texture, sf::Texture& texture_background,
        sf::Texture& texture_playingField, sf::Sprite& sprite, sf::Sprite& sprite_background, sf::Sprite& sprite_field);
};
