#include "Game.h"

int field[M][N] = { 0 };

int figures[7][4]
{
    1,3,5,7, // I
    2,4,5,7, // Z
    3,5,4,6, // S
    3,5,4,7, // T
    2,3,5,7, // L
    3,5,7,6, // J
    2,3,4,5, // O
};

sf::RenderWindow window(sf::VideoMode(720, 960), "TETRIS");
sf::Font font;
sf::SoundBuffer themeBuffer, gameoverBuffer, leveldestroyedBuffer;
sf::Sound themeSound, gameoverSound, leveldestroyedSound;
sf::Texture texture, texture_background, texture_playingField;
sf::Sprite sprite, sprite_background, sprite_field;
sf::Text destroyedLevelsCount, startGameText, nextTetraminoText, escapeText;
int dx = 0, colorNum = 1, n = 0, nextColorNum = 1, nextN = 0;
float timer = 0, baseDelay = 0.3, delay = 0, accelerationPerLevel = 0.05;
bool beginGame = true, gameStarted = false, isPaused = false, gameOver = false, gameoverSoundPlayed = false, isSoundSettingsOpen = false;
Menu menu(window);
EndMenu endMenu(window);
LevelCounter levelCounter;


