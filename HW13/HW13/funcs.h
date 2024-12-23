#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

enum class UserChoice { WordOfDay, RandomWord, Exit };

extern std::vector<std::string> wordDatabase;

std::vector<std::string> loadWordDatabase();

void saveWordDatabase(const std::vector<std::string>& words);

std::string getRandomWord(const std::vector<std::string>& wordDatabase);

void saveWordOfTheDayStatus(bool wordOfTheDayGuessed, const std::string& todayDate);

bool checkWordOfTheDayGuessedInSession();

bool loadWordOfTheDayStatus(bool& wordOfTheDayGuessed, std::string& storedDate, bool& wordOfTheDayGuessedInSession);

std::string getTodayDate();

bool checkGuess(const std::string& secretWord, const std::string& guessedWord, bool& wordOfTheDayGuessed, std::string& todayDate, int& attempts);

bool isSameDay(const std::string& storedDate, const std::string& currentDate);

void playWordleGame(const std::string& secretWord, bool& wordOfTheDayGuessed, std::string& storedDate);

UserChoice convertIntToChoice(int rawInput);