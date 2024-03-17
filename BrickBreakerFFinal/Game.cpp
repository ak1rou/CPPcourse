#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& window)
    : m_window(window), m_isGameActive(true), m_isGamePaused(false), m_ballTextureLoaded(false), m_buffApplied(false), m_pauseMenu(window), m_endMenu(window)
{
    Resources::loadTextures();
    Resources::loadFonts();
    Resources::loadSounds();
    loadBestResults();

    m_collisionBuffer = Resources::getSoundBuffer("collision");
    m_blockDestroyedBuffer = Resources::getSoundBuffer("blockDestroyed");
    m_newLevelBuffer = Resources::getSoundBuffer("newLevel");
    m_gameOverBuffer = Resources::getSoundBuffer("gameOver");
    m_buffBuffer = Resources::getSoundBuffer("buff");

    m_collisionSound.setBuffer(m_collisionBuffer);
    m_blockDestroyedSound.setBuffer(m_blockDestroyedBuffer);
    m_newLevelSound.setBuffer(m_newLevelBuffer); 
    m_gameOverSound.setBuffer(m_gameOverBuffer);
    m_buffSound.setBuffer(m_buffBuffer);

    m_backgroundBuffer = Resources::getSoundBuffer("background");
    m_backgroundSound.setBuffer(m_backgroundBuffer);
    m_backgroundSound.setLoop(true); 
    m_backgroundSound.play();
    m_backgroundSound.setVolume(5);

    m_background = GameObject("background", 0.f, 0.f);
    m_paddle = GameObject("paddle", 320.f, 900.f);
    m_ball = GameObject("whiteBall", 350.f, 820.f);
    m_ballPosition = sf::Vector2f(350.f, 820.f);
    m_ballVelocity = sf::Vector2f(0.1f, -0.1f);

    m_collisionCount = 0;
    m_level = 0;

    m_scoreText.setFont(Resources::getFont("font"));
    m_scoreText.setCharacterSize(28);
    m_scoreText.setFillColor(sf::Color::White);
    m_scoreText.setPosition(15.f, 780.f);
    updateScoreText();

    m_levelText.setFont(Resources::getFont("font"));
    m_levelText.setCharacterSize(28);
    m_levelText.setFillColor(sf::Color::White);
    m_levelText.setPosition(15.f, 810.f);
    updateLevelText(); 
}

void Game::updateScoreText() {
    m_scoreText.setString("YOUR SCORE: " + std::to_string(m_collisionCount));
}

void Game::updateLevelText() {
    m_levelText.setString("CURRENT LEVEL: " + std::to_string(m_level));
}

int Game::getHitsForColor(const std::string& color) const
{
    if (color == "blueBrick") return 1;
    else if (color == "purpleBrick") return 2;
    else if (color == "greenBrick") return 3;
    else if (color == "yellowBrick") return 4;
    else if (color == "redBrick") return 5;
    else return 1; 
}

void Game::handleWallCollisions() {
    if (m_ballPosition.x <= 0 || m_ballPosition.x + m_ball.getSprite().getGlobalBounds().width >= m_window.getSize().x) {
        m_ballVelocity.x = -m_ballVelocity.x;
    }

    if (m_ballPosition.y <= 0 || m_ballPosition.y + m_ball.getSprite().getGlobalBounds().height >= m_window.getSize().y) {
        m_ballVelocity.y = -m_ballVelocity.y;
    }
}

void Game::handlePaddleCollision() 
{
    const double PI = 3.14159265;

    sf::FloatRect paddleBounds = m_paddle.getSprite().getGlobalBounds();
    sf::FloatRect ballBounds = m_ball.getSprite().getGlobalBounds();

    if (paddleBounds.intersects(ballBounds)) {
        float relativeIntersectX = (paddleBounds.left + paddleBounds.width / 2) - (ballBounds.left + ballBounds.width / 2);
        float normalizedRelativeIntersectX = relativeIntersectX / (paddleBounds.width / 2);

        float bounceAngle = normalizedRelativeIntersectX * (PI / 3); 

        float ballSpeed = std::sqrt(m_ballVelocity.x * m_ballVelocity.x + m_ballVelocity.y * m_ballVelocity.y);
        m_ballVelocity.x = -ballSpeed * std::sin(bounceAngle);
        m_ballVelocity.y = -ballSpeed * std::cos(bounceAngle);
    }
}

void Game::handleBrickCollisions()
{
    sf::FloatRect ballBounds = m_ball.getSprite().getGlobalBounds();

    bool collisionHandled = false;

    for (auto it = m_bricks.begin(); it != m_bricks.end(); ++it)
    {
        if (collisionHandled)
        {
            break;
        }

        sf::FloatRect brickBounds = it->getSprite().getGlobalBounds();

        if (ballBounds.intersects(brickBounds))
        {
            m_collisionSound.play();

            int collisionsRequired = m_buff.isActive() ? 3 : 1; 
            int points = std::min(collisionsRequired, it->getCollisionsRequired()); 
            it->decrementCollisionsRequired(points); 
            it->updateText();

            m_collisionCount += points; 
            updateScoreText();

            if (it->getCollisionsRequired() <= 0)
            {
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<int> dis(1, 100);

                int chance = dis(gen);
                if (chance <= 17) {
                    m_buff.applyBuff();
                    m_buff.setBall(&m_ball);
                    std::cout << "buff!" << std::endl;
                }
                it = m_bricks.erase(it);
                m_blockDestroyedSound.play();
            }

            float ballCenterX = ballBounds.left + ballBounds.width / 2;
            float ballCenterY = ballBounds.top + ballBounds.height / 2;
            float brickCenterX = brickBounds.left + brickBounds.width / 2;
            float brickCenterY = brickBounds.top + brickBounds.height / 2;

            float deltaX = ballCenterX - brickCenterX;
            float deltaY = ballCenterY - brickCenterY;

            if (std::abs(deltaX) > std::abs(deltaY))
            {
                m_ballVelocity.x = -m_ballVelocity.x;
            }
            else
            {
                m_ballVelocity.y = -m_ballVelocity.y;
            }
            collisionHandled = true;
        }
    }
}

bool Game::areAllBricksDestroyed() const
{
    return m_bricks.empty();
}

void Game::generateNewLevel()
{
    m_bricks.clear();

    m_level++; 
    updateLevelText();

    const int maxBlocks = 20;
    const float minY = 40.f;
    const float maxY = 520.f;
    const float offsetX = 40.f;

    std::vector<std::pair<sf::Vector2f, std::string>> blockPositions = BlockGenerator::generateBlocks(maxBlocks, minY, maxY, offsetX);

    for (const auto& block : blockPositions)
    {
        m_bricks.emplace_back(block.second, block.first.x, block.first.y, getHitsForColor(block.second));
    }
}

void Game::increaseBallSpeed()
{
    m_ballVelocity *= 1.15f;
}

void Game::run() 
{
    while (m_window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            m_window.close();
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            m_isGamePaused = !m_isGamePaused;

        if (m_isGamePaused) {
            processPauseMenuEvents(event); 
        }
        else if (!m_isGameActive) 
        {
            processEndMenuEvents(event);
        }
        else
        {
            InputManager::processInput(m_window, m_paddle.getSprite());
        }
    }
}

void Game::processEndMenuEvents(sf::Event& event)
{
    m_endMenu.handleEvents(event);
    if (event.key.code == sf::Keyboard::Return)
    {
        switch (m_endMenu.getPressedItem())
        {
        case 1:
            createNewGame();
            break;
        case 2:
            toggleSoundVolume();
            break;
        case 3:
            closeGame();
            break;
        }
    }
}

void Game::update() 
{
    if (!m_isGameActive)
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        processEndMenuEvents(event);

        return;
    }

    if (!m_isGamePaused)
    {
        if (!m_ballTextureLoaded) {
            sf::Texture& whiteBallTexture = Resources::getTexture("whiteBall");
            if (whiteBallTexture.getSize().x == 0 || whiteBallTexture.getSize().y == 0) {
                std::cout << "Failed to load whiteBall texture" << std::endl;
            }
            else {
                m_ballTextureLoaded = true;
                m_ball.getSprite().setTexture(whiteBallTexture);
            }
        }

        if (m_buff.isActive() && !m_buffApplied)
        {
            m_buffApplied = true;
            m_buff.applyBuff(); 
            m_buffSound.play();
            m_buffSound.setVolume(200);
        }

        if (!m_buff.isActive())
        {
            m_buffApplied = false;
            m_buffSound.stop();
        }

        m_ballPosition += m_ballVelocity;
        m_ball.setSpritePosition(m_ballPosition.x, m_ballPosition.y);

        handleWallCollisions();
        handlePaddleCollision();
        handleBrickCollisions();
    }

    if (areAllBricksDestroyed())
    {
        generateNewLevel();
        increaseBallSpeed();
        m_newLevelSound.play();
    }

    if (m_ballPosition.y + m_ball.getSprite().getGlobalBounds().height >= m_window.getSize().y)
    {
        m_backgroundSound.stop();
        m_buffSound.stop();
        m_gameOverSound.play();

        m_isGameActive = false;
    }

    if (m_collisionCount > m_bestScore)
    {
        m_bestScore = m_collisionCount;
    }
    if (m_level > m_bestLevel) 
    {
        m_bestLevel = m_level;
    }

    if (m_buff.isActive() && !m_isGamePaused)
    {
        m_buff.update(); 
    }

    saveBestResults();
}

void Game::processPauseMenuEvents(sf::Event& event)
{
    m_pauseMenu.handleEvents(event);
    if(event.key.code == sf::Keyboard::Return)
    {
        switch (m_pauseMenu.getPressedItem())
        {
        case 1:
            resumeGame();
            break;
        case 2:
            createNewGame();
            break;
        case 3:
            toggleSoundVolume();
            break;
        case 4:
            closeGame();
            break;
        }
    }
}

void Game::loadBestResults() {
    std::ifstream file("best_results.txt");
    if (file.is_open()) {
        file >> m_bestScore >> m_bestLevel;
        file.close();
    }
}

void Game::saveBestResults() {
    std::ofstream file("best_results.txt");
    if (file.is_open()) {
        file << m_bestScore << " " << m_bestLevel;
        file.close();
    }
}

void Game::displayBestResults()
{
    sf::Text bestResultsText;
    bestResultsText.setFont(Resources::getFont("font"));
    bestResultsText.setCharacterSize(28);
    bestResultsText.setFillColor(sf::Color::White);
    bestResultsText.setString("HIGH SCORE: " + std::to_string(m_bestScore) + " SCORE, " + std::to_string(m_bestLevel) + " LEVELS");
    bestResultsText.setPosition(15.f, 840.f);

    m_window.draw(bestResultsText);
}

void Game::resumeGame()
{
    m_isGamePaused = false;
}

void Game::createNewGame() 
{
    m_ballPosition = sf::Vector2f(350.f, 820.f);
    m_ballVelocity = sf::Vector2f(0.1f, -0.1f);
    m_isGameActive = true;
    m_isGamePaused = false;
    m_collisionCount = 0;
    m_level = 0;
    m_bricks.clear();
    m_buff.buffReset();
    generateNewLevel();
    updateScoreText();
    updateLevelText();
    m_backgroundSound.setLoop(true);
    m_backgroundSound.play();
}

void Game::toggleSoundVolume()
{
    static float volume = 100.0f;
    static bool decreasing = true;

    if (decreasing) {
        volume = std::max(volume - 10.0f, 0.0f);
        if (volume <= 0.0f) {
            decreasing = false;
        }
    }
    else {
        volume = std::min(volume + 10.0f, 100.0f);
        if (volume >= 100.0f) {
            decreasing = true;
        }
    }

    m_backgroundSound.setVolume(volume);
    m_collisionSound.setVolume(volume);
    m_blockDestroyedSound.setVolume(volume);
    m_newLevelSound.setVolume(volume);
    m_gameOverSound.setVolume(volume);
    m_buffSound.setVolume(volume);
}

void Game::closeGame()
{
    m_window.close();
}

void Game::render() 
{
    if (m_isGamePaused) {
        m_pauseMenu.render();
    }
    else if (!m_isGameActive)
    {
        m_endMenu.render(); 
    }
    else {
        m_background.draw(m_window);
        m_paddle.draw(m_window);
        m_ball.draw(m_window);

        for (auto& brick : m_bricks) {
            brick.draw(m_window);
        }

        if (m_buff.isActive() && m_buffApplied && m_isGameActive)
        {
            sf::Text ballText;
            ballText.setFont(Resources::getFont("font"));
            ballText.setCharacterSize(64);
            ballText.setFillColor(sf::Color::Black);
            ballText.setString("BALL IN FIRE");
            ballText.setPosition(250.f, 30.f);
            ballText.setOutlineColor(sf::Color::Red);
            ballText.setOutlineThickness(5);
            m_window.draw(ballText);
        }

        m_window.draw(m_scoreText);
        m_window.draw(m_levelText);
        displayBestResults();
    }

    m_window.display();
}
