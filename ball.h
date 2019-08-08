#ifndef BALL_H
#define BALL_H

#include "nature_object.h"

struct Ball : NatureObject
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
            velocity.x *= -1;
            acceleration.x *= -1;
        }

        if(((center.y - radius) <= 0) || ((center.y + radius) > height))
        {
            velocity.y *= -1;
            acceleration.y *= -1;
        }
    }

    void Draw()
    {
        DrawCircle(center, radius);
    }
};

#endif
