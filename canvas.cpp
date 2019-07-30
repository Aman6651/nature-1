#include "canvas.h"

Canvas::Canvas(SDL_Renderer *Renderer_, int PadLeft_, int PadTop_)
    : Renderer(Renderer_), PadLeft(PadLeft_), PadTop(PadTop_)
{
    OriginalPadLeft = PadLeft_;
    OriginalPadTop = PadTop_;

    Clear();
}

void Canvas::Clear()
{
    SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
    SDL_RenderClear(Renderer);
}

void Canvas::DrawPixel(int x, int y)
{
    SDL_RenderDrawPoint(Renderer, x, y);
}

void Canvas::DrawCircle(int xm, int ym, int r)
{
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
    int x = -r, y = 0, err = 2-2*r; /* II. Quadrant */ 
    do {
        DrawPixel(xm-x, ym+y); /*   I. Quadrant */
        DrawPixel(xm-y, ym-x); /*  II. Quadrant */
        DrawPixel(xm+x, ym-y); /* III. Quadrant */
        DrawPixel(xm+y, ym+x); /*  IV. Quadrant */
        r = err;
        if (r <= y) err += ++y*2+1;           /* e_xy+e_y < 0 */
        if (r > x || err > y) err += ++x*2+1; /* e_xy+e_x > 0 or no 2nd y-step */
    } while (x < 0);
}

void Canvas::DrawCircle(const Vec2 &vec, int radius)
{
    DrawCircle(vec.x, vec.y, radius);
}

void Canvas::DrawLine(const Vec2 &tail, const Vec2& head)
{
    SDL_RenderDrawLine(Renderer, tail.x, tail.y, head.x, head.y);
}

void Canvas::Translate(float x, float y)
{
    PadLeft += x;
    PadTop += y;
}

void Canvas::Translate(const Vec2 &vec)
{
    Translate(vec.x, vec.y);
}

void Canvas::ResetTranslation()
{
    PadLeft = OriginalPadLeft;
    PadTop = OriginalPadTop;
}
