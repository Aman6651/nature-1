#ifndef NATURE_H
#define NATURE_H

#include "graphics.h"
#include "ball.h"

class Nature
{
public:
    static Nature *GetInstance();
    void Init();
    void Update(float dt);
    void Render();

private:
    static Nature *Instance;
    int width;
    int height;

    Nature();
    ~Nature();
};

#endif
