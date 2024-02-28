#pragma once
#include <iostream>
#include <cmath>

enum class VectorRelativeState { Identical, coDirected, OppositeDirected, AcuteAngle, ObtuseAngle, RightAngle };

class Vector2d
{
private:
    float x;
    float y;

public:
    Vector2d(float x = 0.0f, float y = 0.0f);
    Vector2d(float x0, float y0, float x1, float y1);
    ~Vector2d();

    float dotProduct(Vector2d& other) const;
    Vector2d negate() const;
    VectorRelativeState getRelativeState(const Vector2d& other) const;
    void scale(float factorX, float factorY);

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

class Vector3d 
{

public:
    float x;
    float y;
    float z;

    Vector3d(float x = 0.0f, float y = 0.0f, float z = 0.0f);
    ~Vector3d();

    Vector3d crossProduct(const Vector3d& other) const;
};
