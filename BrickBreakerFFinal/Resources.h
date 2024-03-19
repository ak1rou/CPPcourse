#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>

class Resources
{
public:
    static void loadTextures();
    static void loadFonts();
    static void loadSounds();
    static sf::Texture& getTexture(const std::string& name);
    static sf::Font& getFont(const std::string& name);
    static sf::SoundBuffer& getSoundBuffer(const std::string& name);

private:
    static std::unordered_map<std::string, sf::Texture> textures;
    static std::unordered_map<std::string, sf::Font> fonts;
    static std::unordered_map<std::string, sf::SoundBuffer> soundBuffers;
};