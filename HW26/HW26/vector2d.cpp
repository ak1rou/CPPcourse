#include "Vector2d.h"

int Vector2d::count = 0;

Vector2d::Vector2d(float x, float y) : x(x), y(y)
{
    count++;
}

Vector2d::Vector2d(float x0, float y0, float x1, float y1) : x(x1 - x0), y(y1 - y0)
{
    count++;
}

Vector2d::~Vector2d()
{
    count--;
}

float Vector2d::dotProduct(Vector2d& other) const
{
    return (x * other.x) + (y * other.y);
}

Vector2d Vector2d::negate() const
{
    return Vector2d(-x, -y);
}

VectorRelativeState Vector2d::getRelativeState(const Vector2d& other) const
{
    float dot = dotProduct(const_cast<Vector2d&>(other));
    float length1 = sqrt(x * x + y * y);
    float length2 = sqrt(other.x * other.x + other.y * other.y);
    float angle = acos(dot / (length1 * length2));
    const double M_PI = 3.14;

    if (angle == 0)
        return VectorRelativeState::Identical;
    else if (dot > 0)
        return VectorRelativeState::coDirected;
    else if (dot < 0)
        return VectorRelativeState::OppositeDirected;
    else {
        if (angle < M_PI / 2)
            return VectorRelativeState::AcuteAngle;
        else if (angle == M_PI / 2)
            return VectorRelativeState::RightAngle;
        else
            return VectorRelativeState::ObtuseAngle;
    }
}

void Vector2d::scale(float factorX, float factorY)
{
    x *= factorX;
    y *= factorY;
}

Vector3d::Vector3d(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3d::~Vector3d() {}

Vector3d Vector3d::crossProduct(const Vector3d& other) const
{
    float newX = (y * other.z) - (z * other.y);
    float newY = (z * other.x) - (x * other.z);
    float newZ = (x * other.y) - (y * other.x);

    return Vector3d(newX, newY, newZ);
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
