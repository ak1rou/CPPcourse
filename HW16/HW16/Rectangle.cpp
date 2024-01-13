#include "Rectangle.h"

Rectangle::Rectangle() : length(0.0), height(0.0) {}

Rectangle::Rectangle(float x, float y) : length(x), height(y) {}

float Rectangle::getArea() const
{
    return length * height;
}

float Rectangle::getPerimeter() const
{
    return 2 * (length + height);
}
