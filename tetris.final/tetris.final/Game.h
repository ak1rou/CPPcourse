#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include "EndMenu.h"
#include "LevelCounter.h"

const int M = 40;
const int N = 20;

extern int field[M][N];
extern int figures[7][4];
extern sf::RenderWindow window;
extern sf::Font font;
extern sf::SoundBuffer themeBuffer, gameoverBuffer, leveldestroyedBuffer;
extern sf::Sound themeSound, gameoverSound, leveldestroyedSound;
extern sf::Texture texture, texture_background, texture_playingField;
extern sf::Sprite sprite, sprite_background, sprite_field;
extern sf::Text destroyedLevelsCount, startGameText, nextTetraminoText, escapeText;
extern int dx, colorNum, n, nextColorNum, nextN;
extern float timer, baseDelay, delay, accelerationPerLevel;
extern bool beginGame, gameStarted, isPaused, gameOver, gameoverSoundPlayed, isSoundSettingsOpen;
extern Menu menu;
extern EndMenu endMenu;
extern LevelCounter levelCounter;

	
