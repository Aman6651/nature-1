#ifndef NATUREOBJECT_H
#define NATUREOBJECT_H

#include "graphics.h"
#include "math_helper.h"

class NatureObject
{
private:
    Graphics *TheGraphics;
    SDL_Renderer *Renderer;

protected:
    NatureObject();
    ~NatureObject();
    void DrawPixel(int x, int y);
    void DrawLine(const Vec2 &tail, const Vec2 &head);
    void DrawCircle(int x, int y, int r);
    void DrawCircle(const Vec2 &center, float radius);

public:
    virtual void Update(float dt, Input *input)=0;
    virtual void Draw()=0;
};

#endif
