#ifndef NATURE_H
#define NATURE_H

#include "canvas.h"
#include "ball.h"

class Nature
{
public:
    Nature(Canvas &canvas, int width, int height);
    void Update(float dt);
    void Draw();

private:
    Canvas canvas;
    int width;
    int height;
};

#endif
