#include "Resources.h"

std::unordered_map<std::string, sf::Texture> Resources::textures;
std::unordered_map<std::string, sf::Font> Resources::fonts;
std::unordered_map<std::string, sf::SoundBuffer> Resources::soundBuffers;

void Resources::loadTextures()
{
    sf::Texture whiteBallTexture;
    whiteBallTexture.loadFromFile("resources/whiteBall.png");
    textures["whiteBall"] = whiteBallTexture;

    sf::Texture blackBallTexture;
    blackBallTexture.loadFromFile("resources/blackBall.png");
    textures["blackBall"] = blackBallTexture;

    sf::Texture yellowBrickTexture;
    yellowBrickTexture.loadFromFile("resources/yellowBrick.png");
    textures["yellowBrick"] = yellowBrickTexture;

    sf::Texture redBrickTexture;
    redBrickTexture.loadFromFile("resources/redBrick.png");
    textures["redBrick"] = redBrickTexture;

    sf::Texture purpleBrickTexture;
    purpleBrickTexture.loadFromFile("resources/purpleBrick.png");
    textures["purpleBrick"] = purpleBrickTexture;

    sf::Texture blueBrickTexture;
    blueBrickTexture.loadFromFile("resources/blueBrick.png");
    textures["blueBrick"] = blueBrickTexture;

    sf::Texture greenBrickTexture;
    greenBrickTexture.loadFromFile("resources/greenBrick.png");
    textures["greenBrick"] = greenBrickTexture;

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("resources/background.png");
    textures["background"] = backgroundTexture;

    sf::Texture paddleTexture;
    paddleTexture.loadFromFile("resources/paddle.png");
    textures["paddle"] = paddleTexture;
}

void Resources::loadFonts()
{
    sf::Font font;
    font.loadFromFile("resources/Stengazeta-Regular_5.ttf"); 
    fonts["font"] = font; 
}

void Resources::loadSounds()
{
    sf::SoundBuffer backgroundBuffer;
    backgroundBuffer.loadFromFile("resources/backgroundSound.mp3");
    soundBuffers["background"] = backgroundBuffer;

    sf::SoundBuffer blockDestroyedBuffer;
    blockDestroyedBuffer.loadFromFile("resources/blockDestroyedSound.mp3");
    soundBuffers["blockDestroyed"] = blockDestroyedBuffer;

    sf::SoundBuffer collisionBuffer;
    collisionBuffer.loadFromFile("resources/collisionSound.mp3");
    soundBuffers["collision"] = collisionBuffer;

    sf::SoundBuffer gameOverBuffer;
    gameOverBuffer.loadFromFile("resources/gameOverSound.mp3");
    soundBuffers["gameOver"] = gameOverBuffer;

    sf::SoundBuffer newLevelBuffer;
    newLevelBuffer.loadFromFile("resources/newLevelSound.mp3");
    soundBuffers["newLevel"] = newLevelBuffer;

    sf::SoundBuffer buffBuffer;
    buffBuffer.loadFromFile("resources/buffSound.mp3");
    soundBuffers["buff"] = buffBuffer;
}

sf::SoundBuffer& Resources::getSoundBuffer(const std::string& name)
{
    return soundBuffers.at(name);
}

sf::Texture& Resources::getTexture(const std::string& name)
{
    return textures.at(name);
}

sf::Font& Resources::getFont(const std::string& name)
{
    return fonts.at(name);
}
