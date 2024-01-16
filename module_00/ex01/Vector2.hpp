#ifndef VECTOR2_HPP
# define VECTOR2_HPP

class Vector2
{
private:
    float   x;
    float   y;

public:
    Vector2();
    Vector2(float x, float y);
    Vector2(const Vector2&);
    Vector2& operator=(const Vector2& rhs);
    ~Vector2();

    int get_x() const;
    int get_y() const;

    void    set_x(float);
    void    set_y(float);
};

#endif