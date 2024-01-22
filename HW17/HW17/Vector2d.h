#pragma once
#include <iostream>

class Vector2d
{
private:
    float x;
    float y;

public:
    Vector2d(float x = 0.0f, float y = 0.0f);
    ~Vector2d();

    Vector2d& operator=(const Vector2d& other);

    Vector2d operator+(const Vector2d& secondVector) const;
    Vector2d operator-(const Vector2d& secondVector) const;

    friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);
    friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);

    float operator()() const;
    float& operator[](int i);

    friend std::ostream& operator<<(std::ostream& os, const Vector2d& vector);
    friend std::istream& operator>>(std::istream& is, Vector2d& vector);

    static int getCount();

private:
    static int count;
};