#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include "Menu.h"
#include "EndMenu.h"
#include "LevelCounter.h"
#include "ResourceInitializer.h"
#include "Game.h"

using namespace sf;

struct Point { int x, y; } a[4], b[4], next[4];

bool check() 
{
    for (int i = 0; i < 4; i++)
        if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return 0;
        else if (field[a[i].y][a[i].x]) return 0;

    return 1;
}

int main()
{
    sf::RenderWindow window;
    sf::Font font;
    sf::SoundBuffer themeBuffer, gameoverBuffer, leveldestroyedBuffer;
    sf::Sound themeSound, gameoverSound, leveldestroyedSound;
    sf::Text destroyedLevelsCount, startGameText, nextTetraminoText, escapeText;
    sf::Texture texture, texture_background, texture_playingField;
    sf::Sprite sprite, sprite_background, sprite_field;
    Menu menu(window);
    EndMenu endMenu(window);
    LevelCounter levelCounter;

    ResourceInitializer::initializeResources(window, font, themeBuffer, gameoverBuffer, leveldestroyedBuffer, themeSound, gameoverSound,
        leveldestroyedSound, destroyedLevelsCount, startGameText, nextTetraminoText, escapeText, texture, texture_background, 
        texture_playingField, sprite, sprite_background, sprite_field);

    int dx = 0;

    bool rotate = 0;

    int colorNum = 1;

    bool beginGame = true;

    int n = rand() % 7;

    int nextColorNum = 1;
    int nextN = rand() % 7;

    float timer = 0;

    float baseDelay = 0.3;
    float delay = 0;
    float accelerationPerLevel = 0.05;

    bool gameStarted = false;

    bool isPaused = false;

    bool gameOver = false;

    bool gameoverSoundPlayed = false;

    bool isSoundSettingsOpen = false;

    Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        for (int i = 0; i < 4; i++)
        {
            if (field[a[i].y][a[i].x] != 0)
            {
                gameOver = true;
                break;
            }
        }

        if (gameOver && !gameoverSoundPlayed)
        {
            gameoverSound.play();
            gameoverSoundPlayed = true;
        }

        if (gameOver)
        {
            themeSound.stop();
            window.clear();
            endMenu.draw(window);
            window.display();

            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();

                if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::Up || event.key.code == Keyboard::W)
                        endMenu.moveUp();
                    else if (event.key.code == Keyboard::Down || event.key.code == Keyboard::S)
                        endMenu.moveDown();
                    else if (event.key.code == Keyboard::Return) {
                        switch (endMenu.getPressedItem()) {
                        case 1:
                            levelCounter.reset();
                            for (int i = 0; i < M; i++) {
                                for (int j = 0; j < N; j++) {
                                    field[i][j] = 0;
                                }
                            }
                            beginGame = true;
                            gameOver = false;
                            themeSound.play();
                            gameoverSoundPlayed = false;
                            break;
                        case 2:
                            window.close();
                            break;
                        }
                    }
                }
            }
            continue;
        }

        if (!gameStarted)
        {
            themeSound.setLoop(true);
            themeSound.play();
            window.clear(Color::Black);
            window.draw(startGameText);
            window.display();

            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();

                if (event.type == Event::KeyPressed)
                {
                    if (event.key.code == Keyboard::Enter)
                    {
                        gameStarted = true;
                    }
                }
            }

            continue;
        }

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (isPaused)
            {
                if (event.type == Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        isPaused = !isPaused;
                        menu.draw(window);
                    }
                    else if (event.key.code == sf::Keyboard::Up || event.key.code == Keyboard::W)
                    {
                        menu.moveUp();
                    }
                    else if (event.key.code == sf::Keyboard::Down || event.key.code == Keyboard::S)
                    {
                        menu.moveDown();
                    }
                    else if (event.key.code == sf::Keyboard::Return)
                    {
                        switch (menu.getPressedItem())
                        {
                        case 1:
                            isPaused = false;
                            break;
                        case 2:
                            levelCounter.reset();
                            for (int i = 0; i < M; i++) {
                                for (int j = 0; j < N; j++) {
                                    field[i][j] = 0;
                                }
                            }
                            beginGame = true;
                            gameStarted = true;
                            isPaused = false;
                            break;
                        case 3:
                            isSoundSettingsOpen = !isSoundSettingsOpen;
                            if (isSoundSettingsOpen) {
                                themeSound.setVolume(0);
                            }
                            else {
                                themeSound.setVolume(100);
                            }
                            break;
                        case 4:
                            window.close();
                            break;
                        }
                    }
                }
            }
            else
            {
                if (event.type == Event::KeyPressed)
                {
                    if (event.key.code == Keyboard::Up || event.key.code == Keyboard::W)
                        rotate = true;
                    else if (event.key.code == Keyboard::Left || event.key.code == Keyboard::A)
                        dx = -1;
                    else if (event.key.code == Keyboard::Right || event.key.code == Keyboard::D)
                        dx = 1;
                    else if (event.key.code == Keyboard::Down || event.key.code == Keyboard::S)
                        delay = 0.025;
                    else if (event.key.code == sf::Keyboard::Escape)
                    {
                        isPaused = !isPaused;
                        menu.draw(window);
                    }
                }
            }
        }

        if (!gameOver && !isPaused)
        {
            for (int i = 0; i < 4; i++)
            {
                b[i] = a[i];
                a[i].x += dx;
            }

            if (!check())
            {
                for (int i = 0; i < 4; i++)
                    a[i] = b[i];
            }

            if (rotate)
            {
                Point p = a[1];
                for (int i = 0; i < 4; i++)
                {
                    int x = a[i].y - p.y;
                    int y = a[i].x - p.x;
                    a[i].x = p.x - x;
                    a[i].y = p.y + y;
                }

                if (!check())
                {
                    for (int i = 0; i < 4; i++)
                        a[i] = b[i];
                }
            }

            if (timer > delay)
            {
                for (int i = 0; i < 4; i++)
                {
                    b[i] = a[i];
                    a[i].y += 1;
                }

                if (!check())
                {
                    for (int i = 0; i < 4; i++)
                        field[b[i].y][b[i].x] = colorNum;
                    colorNum = nextColorNum;
                    n = nextN;
                    nextColorNum = 1 + rand() % 7;
                    nextN = rand() % 7;

                    for (int i = 0; i < 4; i++)
                    {
                        next[i].x = figures[nextN][i] % 2;
                        next[i].y = figures[nextN][i] / 2;
                    }

                    for (int i = 0; i < 4; i++)
                    {
                        a[i].x = figures[n][i] % 2;
                        a[i].y = figures[n][i] / 2;
                    }
                }

                timer = 0;
            }

            int destroyedLevels = 0;
            for (int i = 0; i < M; i++)
            {
                bool isRowFull = true;
                for (int j = 0; j < N; j++)
                {
                    if (field[i][j] == 0)
                    {
                        isRowFull = false;
                        break;
                    }
                }
                if (isRowFull)
                {
                    destroyedLevels++;

                    for (int k = i; k > 0; k--)
                    {
                        for (int j = 0; j < N; j++)
                        {
                            field[k][j] = field[k - 1][j];
                        }
                    }

                    for (int j = 0; j < N; j++)
                    {
                        field[0][j] = 0;
                    }
                }
            }

            if (destroyedLevels > 0)
            {
                levelCounter.increaseDestroyedLevels();
                leveldestroyedSound.play();
            }

            if (beginGame)
            {
                beginGame = false;
                n = rand() % 7;
                for (int i = 0; i < 4; i++)
                {
                    a[i].x = figures[n][i] % 2;
                    a[i].y = figures[n][i] / 2;
                }

                for (int i = 0; i < 4; i++)
                {
                    next[i].x = figures[nextN][i] % 2;
                    next[i].y = figures[nextN][i] / 2;
                }
            }

            dx = 0;
            rotate = 0;
            delay = baseDelay - accelerationPerLevel * levelCounter.getDestroyedLevels();
        }

        destroyedLevelsCount.setString("CURRENT SCORE: " + std::to_string(levelCounter.getDestroyedLevels()) +
            "\nBEST SCORE: " + std::to_string(levelCounter.getBestScore()));

        window.clear(Color::White);
        window.draw(sprite_background);
        sprite_field.setPosition(50, 50);
        window.draw(sprite_field);
        window.draw(nextTetraminoText);
        window.draw(escapeText);

        FloatRect textBounds = nextTetraminoText.getGlobalBounds();
        float tetraminoTextX = textBounds.left;
        float tetraminoTextY = textBounds.top + textBounds.height;

        int tetraminoWidth = 4;

        float tetraminoX = tetraminoTextX + (textBounds.width - tetraminoWidth * 18) / 2 + 20;
        float tetraminoY = tetraminoTextY + 15;

        for (int i = 0; i < 4; i++) {
            sprite.setTextureRect(IntRect(nextColorNum * 18, 0, 18, 18));
            sprite.setPosition(tetraminoX + next[i].x * 18, tetraminoY + next[i].y * 18);
            window.draw(sprite);
        }

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (field[i][j] == 0)
                    continue;
                sprite.setTextureRect(IntRect(field[i][j] * 18, 0, 18, 18));
                sprite.setPosition(j * 18, i * 18);
                sprite.move(50, 50);
                window.draw(sprite);
            }
        }

        for (int i = 0; i < 4; i++)
        {
            sprite.setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
            sprite.setPosition(a[i].x * 18, a[i].y * 18);
            sprite.move(50, 50);
            window.draw(sprite);
        }

        if (isPaused)
        {
            menu.draw(window);
        }

        window.draw(destroyedLevelsCount);

        window.display();
    }

    return 0;
}


