#include <iostream>
#include "graphics.h"
#include "nature.h"

#define WIDTH 640
#define HEIGHT 360

int main()
{
    if(!Graphics::GetInstance()->Init(WIDTH, HEIGHT))
    {
        std::cout << "Graphics did not initialize" << std::endl;
        return 0;
    }
    //Nature::GetInstance()->Init();

    bool Running = true;
    const unsigned int GameHz = 60;
    float MSPerFrame = 1.0f / GameHz * 1000;
    Uint32 LastTick = SDL_GetTicks();
    Uint32 ElapsedTime;

    //Canvas canvas(Renderer);
    //Nature nature(canvas, WIDTH, HEIGHT);

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

            //Nature.Update(dt);
            //Nature.Render();

            SDL_RenderPresent(Graphics::GetInstance()->GetRenderer());
            LastTick = SDL_GetTicks();
        }
    }

    return 0;
}
