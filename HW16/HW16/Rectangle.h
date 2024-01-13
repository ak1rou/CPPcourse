#pragma once

class Rectangle
{
private:
    float length;
    float height;

public:
    Rectangle();
    Rectangle(float x, float y);
    float getArea() const;
    float getPerimeter() const;
};
