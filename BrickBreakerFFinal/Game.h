#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <utility>
#include <chrono>
#include "GameObject.h"
#include "Resources.h"
#include "BlockGenerator.h"
#include "InputManager.h"
#include "Buff.h"
#include "Menu.h"

class Game
{
public:
    Game(sf::RenderWindow& window);
    void run();

private:
    void update();
    void processEvents();
    void processPauseMenuEvents(sf::Event& event);
    void processEndMenuEvents(sf::Event& event);
    void resumeGame();
    void createNewGame();
    void toggleSoundVolume();
    void closeGame();
    void render();
    void handleWallCollisions();
    void handlePaddleCollision();
    void handleBrickCollisions();
    void generateNewLevel();
    void increaseBallSpeed();
    void loadBestResults();
    void saveBestResults();
    void displayBestResults();
    void updateScoreText();
    void updateLevelText();
    int getHitsForColor(const std::string& color) const;
    bool areAllBricksDestroyed() const;

    sf::RenderWindow& m_window;
    GameObject m_background;
    GameObject m_paddle;
    GameObject m_ball;
    Menu m_pauseMenu;
    EndMenu m_endMenu;
    sf::Vector2f m_ballPosition;
    sf::Vector2f m_ballVelocity;
    sf::Text m_scoreText;
    sf::Text m_levelText;
    std::vector<GameObject> m_bricks;
    Buff m_buff;

    bool m_isGameActive;
    bool m_isGamePaused;
    bool m_ballTextureLoaded;
    bool m_buffApplied;
    bool m_buffTimerRunning;
    int m_collisionCount;
    int m_level;
    int m_bestScore;
    int m_bestLevel;

    sf::SoundBuffer m_collisionBuffer;
    sf::SoundBuffer m_blockDestroyedBuffer;
    sf::SoundBuffer m_newLevelBuffer;
    sf::SoundBuffer m_gameOverBuffer;
    sf::SoundBuffer m_backgroundBuffer;
    sf::SoundBuffer m_buffBuffer;
    sf::Sound m_collisionSound;
    sf::Sound m_blockDestroyedSound;
    sf::Sound m_newLevelSound;
    sf::Sound m_gameOverSound;
    sf::Sound m_backgroundSound;
    sf::Sound m_buffSound;
};
