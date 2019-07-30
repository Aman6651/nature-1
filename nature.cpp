#include "nature.h"

static Vec2 center = { 100, 100 };
static float radius = 16;
static Vec2 velocity = { 0.5, 0.37 };
static Vec2 tail = { 0, 0 };

struct Ball
{
    Vec2 position;
    Vec2 velocity;
    
    Ball() : velocity(Vec2(0.5, 0.37))
    {
    }
};

static Ball balls[10];

Nature::Nature(Canvas &canvas_, int width_, int height_) 
    : canvas(canvas_), width(width_), height(height_)
{
    for(int i=0; i<10; i++)
    {
        Ball &ball = balls[i];
        ball.position = { 0, (float)i };
        ball.velocity = { (float)i, (float)-i };
    }
}

void Nature::Update(float dt)
{
    for(int i=0; i<10; i++)
    {
        Vec2 &position = &(balls[i].position);
        Vec2 &velocity = &(balls[i].velocity);
        position += velocity * dt;

        if(((center.x - radius) <= 0) || ((center.x + radius) > width))
        {
            velocity.x = velocity.x * -1;
        }

        if(((center.y - radius) <= 0) || ((center.y + radius) > height))
        {
            velocity.y = velocity.y * -1;
        }
    }
}

void Nature::Draw()
{
    canvas.Clear();
    for(int i=0; i<10; i++)
        canvas.DrawCircle(balls[i], radius);
    canvas.DrawLine(tail, center);
}
