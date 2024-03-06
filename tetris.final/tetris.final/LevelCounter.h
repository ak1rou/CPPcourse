#pragma once

#include <fstream>

class LevelCounter {
public:
    LevelCounter();

    void increaseDestroyedLevels();
    int getDestroyedLevels() const;
    void reset();
    int getBestScore() const;

private:
    int destroyedLevels;
    int bestScore;

    void saveBestScore();
    void loadBestScore();
};