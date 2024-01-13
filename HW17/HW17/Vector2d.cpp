#include "Vector2d.h"
#include <cmath>

int Vector2d::count = 0;

Vector2d::Vector2d(float x, float y) : x(x), y(y) 
{
    count++;
}

Vector2d::~Vector2d()
{
    count--;
}


Vector2d& Vector2d::operator=(const Vector2d& other) 
{
    if (this != &other) 
    {
        x = other.x;
        y = other.y;
    }
    return *this;
}

Vector2d Vector2d::operator+(const Vector2d& secondVector) const 
{
    return Vector2d(x + secondVector.x, y + secondVector.y);
}

Vector2d Vector2d::operator-(const Vector2d& secondVector) const
{
    return Vector2d(x - secondVector.x, y - secondVector.y);
}

Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector) 
{
    return Vector2d(leftVector.x + rightVector.x, leftVector.y + rightVector.y);
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector)
{
    return Vector2d(leftVector.x - rightVector.x, leftVector.y - rightVector.y);
}

float Vector2d::operator()() const 
{
    return sqrt(x * x + y * y);
}

float& Vector2d::operator[](int i) 
{
    if (i == 0)
    {
        return x;
    }
    else if (i == 1)
    {
        return y;
    }
    else 
    {
        throw std::out_of_range("Index out of range");
    }
}

std::ostream& operator<<(std::ostream& os, const Vector2d& vector)
{
    os << "{" << vector.x << "; " << vector.y << "}";
    return os;
}

std::istream& operator>>(std::istream& is, Vector2d& vector)
{
    is >> vector.x >> vector.y;
    return is;
}

int Vector2d::getCount() 
{
    return count;
}
