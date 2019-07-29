#include "nature.h"

Canvas::Canvas(SDL_Renderer *Renderer_, int PadLeft_, int PadTop_)
    : Renderer(Renderer_), PadLeft(PadLeft_), PadTop(PadTop_)
{
}

void Canvas::DrawEllipse(Vec2 center, float radius)
{
    std::cout << "Drawing Ellipse @ (" << center.x << ", " << center.y << "), radius = " << radius << std::endl;
}
