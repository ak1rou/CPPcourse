#include <iostream>
#include "functions.h"

void translateArray(int numbers[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (numbers[i] > 0)
        {
            numbers[i] *= 2;
        }
        else
        {
            numbers[i] = 0;
        }
    }
}

void toUppercase(char str[]) 
{
    int length = strlen(str);

    for (int i = 0; i < length; ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = toupper(str[i]);
        }
    }
}

bool isPalindrome(const char str[])
{
    int length = strlen(str);

    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        while (!isalnum(str[start]) && start < end) 
        {
            start++;
        }

        while (!isalnum(str[end]) && start < end)
        {
            end--;
        }

        if (tolower(str[start]) != tolower(str[end]))
        {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

void parseStringLetters(const char str[], int& vowelsCount, int& consonantsCount)
{
    vowelsCount = 0;
    consonantsCount = 0;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        char currentChar = tolower(str[i]);

        if (isalpha(currentChar))
        {
            if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' || currentChar == 'u')
            {
                vowelsCount++;
            }
            else
            {
                consonantsCount++;
            }
        }
    }
}

bool isEqual(const char str1[], const char str2[])
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
        i++;
    }

    return str1[i] == '\0' && str2[i] == '\0';
}