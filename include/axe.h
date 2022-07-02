#ifndef AXE_H
#define AXE_H
#include "raylib.h"
#include "../include/collider.h"

class Axe
{
private:
    float speed{10};
    int length{50};

    Vector2 position;
    Collider collider;
public:
    Collider* collider_axe;
    
    Axe();
    void Update();
    void Render();
    ~Axe();
};
#endif