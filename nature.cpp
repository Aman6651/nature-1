#include <iostream>
#include "nature.h"

Nature* Nature::Instance = NULL;

Nature* Nature::GetInstance()
{
    if(Instance == NULL)
    {
        Instance = new Nature();
    }
    return Instance;
}

void Nature::Init(int width, int height)
{
    ball = Ball();
    Width = width;
    Height = height;
}

void Nature::Update(float dt)
{
    ball.Update(dt);
    ball.CheckEdges(Width, Height);
}

void Nature::Render()
{
    Graphics::GetInstance()->Clear();

    // Render Nature Objects
    ball.Draw();
    
    Graphics::GetInstance()->Flip();
}

Nature::Nature()
{
}

Nature::~Nature()
{
}
