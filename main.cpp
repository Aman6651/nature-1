
#include <iostream>
#include "graphics.h"
#include "nature.h"
#include <time.h>

#define WIDTH 640
#define HEIGHT 360


int main()
{
    srand(time(NULL));

    if(!Graphics::GetInstance()->Init(WIDTH, HEIGHT))
    {
        std::cout << "Graphics did not initialize" << std::endl;
        return 0;
    }
    Nature::GetInstance()->Init(WIDTH, HEIGHT);
    Input input;

    bool Running = true;
    const unsigned int GameHz = 60;
    float MSPerFrame = 1.0f / GameHz * 1000;
    Uint32 LastTick = SDL_GetTicks();
    Uint32 ElapsedTime;

    while(Running)
    {
        SDL_Event Event;
        while(SDL_PollEvent(&Event))
        {
            switch(Event.type)
            {
                case SDL_QUIT:
                {
                    Running = false;
                } break;
            }
        }

        ElapsedTime = SDL_GetTicks() - LastTick;
        if(ElapsedTime >= MSPerFrame)
        {
            float dt = ElapsedTime / 1000.f;

            SDL_GetMouseState(&input.MouseX, &input.MouseY);

            Nature::GetInstance()->Update(dt, &input);
            Nature::GetInstance()->Render();

            LastTick = SDL_GetTicks();
        }
    }

    return 0;
}
