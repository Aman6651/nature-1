#include "nature.h"

#define WIDTH 640
#define HEIGHT 360

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *Window = SDL_CreateWindow("Nature", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

    bool Running = true;
    const unsigned int GameHz = 60;
    float MSPerFrame = 1.0f / GameHz * 1000;
    Uint32 LastTick = SDL_GetTicks();
    Uint32 ElapsedTime;

    Canvas canvas(Renderer);
    Nature nature(canvas, WIDTH, HEIGHT);

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
            nature.Update(ElapsedTime);
            nature.Draw();
            SDL_RenderPresent(Renderer);
            LastTick = SDL_GetTicks();
        }
    }

    return 0;
}
