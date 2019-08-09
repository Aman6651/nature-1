#ifndef MATH_HELPER_H
#define MATH_HELPER_H

#include <cmath>
#include <cstdlib>

static float random_between(float start, float end)
{
    return (rand() % 1000 / 1000.0f) * (int)(end - start) + start;
}

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

    float magnitude()
    {
        return sqrt(x*x + y*y);
    }

    void normalize()
    {
        float mag = magnitude();
        if(mag != 0)
        {
            x /= mag;
            y /= mag;
        }
    }

    static Vec2 Random()
    {
        float randx = random_between(-5, 5);
        float randy = random_between(-5, 5);
        return Vec2(randx, randy);
    }
};


#endif
