#include "LevelCounter.h"

LevelCounter::LevelCounter() : destroyedLevels(0) {
    loadBestScore();
}

void LevelCounter::increaseDestroyedLevels() {
    destroyedLevels++;

    if (destroyedLevels > bestScore) {
        bestScore = destroyedLevels;
        saveBestScore();
    }
}

int LevelCounter::getDestroyedLevels() const {
    return destroyedLevels;
}

void LevelCounter::reset() {
    destroyedLevels = 0;
}

int LevelCounter::getBestScore() const {
    return bestScore;
}

void LevelCounter::saveBestScore() {
    std::ofstream file("high_score.txt");
    if (file.is_open()) {
        file << bestScore;
        file.close();
    }
}

void LevelCounter::loadBestScore() {
    std::ifstream file("high_score.txt");
    if (file.is_open()) {
        file >> bestScore;
        file.close();
    }
}
