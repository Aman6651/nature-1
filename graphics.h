#ifndef GRAPHICS_H
#define GRAPHICS_H

#ifdef __APPLE__
#include "SDL.h"
#elif __linux__
#include <SDL.h>
#endif

class Graphics
{
public: 
    static Graphics *GetInstance();
    SDL_Renderer *GetRenderer();
    bool Init(int width, int height);

private:
    static Graphics *Instance;
    SDL_Window *Window;
    SDL_Renderer *Renderer;
    bool IsInitialized;
    int Width;
    int Height;

private:
    Graphics();
    ~Graphics();
};

#endif
