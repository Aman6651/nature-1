#ifndef CANVAS_H
#define CANVAS_H

#include <iostream>
#include "SDL.h"
#include "math_helper.h"

class Canvas
{
public:
    Canvas(SDL_Renderer *Renderer, int PadLeft = 0, int PadTop = 0);

    void DrawPixel(int x, int y);
    void DrawCircle(int x, int y, int radius);
    void DrawCircle(const Vec2 &center, int radius);
    void DrawLine(const Vec2 &tail, const Vec2 &head);
    void DrawSquare(float x, float y, float length);

    void Translate(float x, float y);
    void Translate(const Vec2 &vec);

    void Clear();
    void Draw();

private:
    SDL_Renderer *Renderer;
    unsigned int PadLeft, OriginalPadLeft;
    unsigned int PadTop, OriginalPadTop;

    void ResetTranslation();
};

#endif
