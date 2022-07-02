#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"

class player {
private:
    Vector2 position;
    float speed;
public:
    player(int initial_posX,int initial_posY);
    virtual void Update(void);
    virtual void Render(void);
    ~player(void);
};

#endif