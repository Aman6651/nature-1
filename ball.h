#ifndef BALL_H
#define BALL_H

#include "math_helper.h"

struct Ball
{
    float radius = 8;
    Vec2 center;
    Vec2 velocity;
    Vec2 acceleration;
    
    Ball()
    {
        center = Vec2(rand() % 640, rand() % 320);
        velocity = Vec2(rand() % 5, rand() % 5);
        acceleration = Vec2(10, 10);
    }

    void Update(float dt)
    {
        velocity += acceleration * dt;
        //Limit(10);
        center += velocity * dt;
    }

    void Limit(float max)
    {
        if(velocity.magnitude() > max)
        {
            velocity.normalize();
            velocity *= max;
        }
    }

    void CheckEdges(int width, int height)
    {
        if(((center.x - radius) <= 0) || ((center.x + radius) > width))
        {
            acceleration.x *= -1;
        }

        if(((center.y - radius) <= 0) || ((center.y + radius) > height))
        {
            acceleration.y *= -1;
        }
    }
};

#endif
