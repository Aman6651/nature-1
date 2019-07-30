#ifndef MATH_HELPER_H
#define MATH_HELPER_H

struct Vec2
{
    float x;
    float y;

    Vec2() : x(0), y(0)
    {

    }

    Vec2(float x_, float y_)
    {
        x = x_;
        y = y_;
    }

    Vec2& operator+=(const Vec2 &rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    Vec2& operator*=(float s)
    {
        x *= s;
        y *= s;
        return *this;
    }

    Vec2 operator*(float s)
    {
        return Vec2(s*x, s*y);
    }
};


#endif
