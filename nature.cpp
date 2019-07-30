#include "nature.h"

static Ball balls[10];

Nature::Nature(Canvas &canvas_, int width_, int height_) 
    : canvas(canvas_), width(width_), height(height_)
{
    for(int i=0; i<10; i++)
        balls[i].center = Vec2(rand() % width/2, rand() % height/2);
}

void Nature::Update(float dt)
{
    for(int i=0; i<10; i++)
    {
        balls[i].Update(dt);
        balls[i].CheckEdges(width, height);
    }
}

void Nature::Draw()
{
    canvas.Clear();

    for(int i=0; i<10; i++)
    {
        canvas.DrawCircle(balls[i].center, balls[i].radius);
    }
}
