#include "Vector2.hpp"

Vector2::Vector2() : x(0), y(0)
{

}

Vector2::Vector2(float _x, float _y) : x(_x), y(_y)
{

}

Vector2::Vector2(const Vector2& other)
{
    this->x = other.x;
    this->y = other.y;
}

Vector2& Vector2::operator=(const Vector2& rhs)
{
    if (this == &rhs)
        return (*this);
    this->x = rhs.x;
    this->y = rhs.y;
    return (*this);
}

Vector2::~Vector2()
{

}

int Vector2::get_x() const
{
    return (this->x);
}

int Vector2::get_y() const
{
    return (this->y);
}

void    Vector2::set_x(float x)
{
    this->x = x;
}

void    Vector2::set_y(float y)
{
    this->y = y;
}