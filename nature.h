#ifndef NATURE_H
#define NATURE_H

#include "graphics.h"
#include "ball.h"

class Nature
{
public:
    static Nature *GetInstance();
    void Init(int width, int height);
    void Update(float dt);
    void Render();

private:
    static Nature *Instance;
    int Width;
    int Height;

    // Nature Objects to be rendered to screen
    Ball ball;

    Nature();
    ~Nature();
};

#endif
