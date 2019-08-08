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

static Ball ball;

void Nature::Init()
{
    ball.center = {100, 200};
}

void Nature::Update(float dt)
{
}

void Nature::Render()
{
    // Clear Screen
    Graphics::GetInstance()->Clear();

    // Render Nature Objects
    ball.Draw();
    
    // Flip Buffer
}

Nature::Nature()
{
}

Nature::~Nature()
{
}
