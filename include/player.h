#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"

class Player {
private:
    Vector2 position;
    float speed {10};
    float radius {25};
public:
    Player(int initial_posX,int initial_posY);
    virtual void Update();
    virtual void Render();
    ~Player();
};

#endif