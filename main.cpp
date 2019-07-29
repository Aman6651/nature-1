#include "nature.h"

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *Window = SDL_CreateWindow("Vectors", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 360, SDL_WINDOW_SHOWN);
    SDL_Renderer *Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

    bool Running = true;
    const unsigned int GameHz = 1;
    float MSPerFrame = 1.0f / GameHz * 1000;
    Uint32 LastTick = SDL_GetTicks();
    Uint32 ElapsedTime;

    Canvas canvas(Renderer, 0, 0);

    float radius = 16;
    float x = 100;
    float y = 100;
    float xspeed = 1;
    float yspeed = 3.3;

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

        if(ElapsedTime >= MSPerFrame)
        {
            // Nature Update

            SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
            SDL_RenderClear(Renderer);

            // Nature Draw
            canvas.DrawEllipse(Vec2(100, 200), 16);

            SDL_RenderPresent(Renderer);

            LastTick = SDL_GetTicks();
        }
    }

    return 0;
}
