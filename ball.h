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
        center = Vec2(320, 160);
        velocity = Vec2(-4, 10);
        acceleration = Vec2(0.1, 1);
    }

    void Update(float dt, Input *input)
    {
        Vec2 MousePosition(input->MouseX, input->MouseY);
        acceleration = MousePosition - center;

        velocity += acceleration * dt;
        Limit(100);
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
        if (center.x < 0)
            center.x = width;
        else if (center.x > width)
            center.x = 0;
        
        if (center.y < 0)
            center.y = height;
        else if (center.y > height)
            center.y = 0;
    }

    void Draw()
    {
        DrawCircle(center, radius);
        DrawLine(center, center + velocity);
    }
};

#endif
