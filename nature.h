#ifndef NATURE_H
#define NATURE_H

#include <iostream>
#include "SDL.h"
#include "math_helper.h"

class Canvas
{
public:
    void DrawEllipse(float x, float y, float radius);
    void DrawEllipse(Vec2 center, float radius);
    void DrawSquare(float x, float y, float length);

    Canvas(SDL_Renderer *Renderer, int PadLeft = 0, int PadTop = 0);

private:
    SDL_Renderer *Renderer;
    unsigned int PadLeft;
    unsigned int PadTop;
};

#endif
