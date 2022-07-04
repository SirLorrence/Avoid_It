#ifndef PLAYER_H
#define PLAYER_H
#include "../include/raylib.h"
#include "../include/collider.h"

class Player {
private:
    float kRadius {25.0f};
    float speed {10};

    Vector2 position;
    Collider collider;

public:
    // float* radius;
    Collider *collider_player;

    Player(); 
    void ResetPoint();
    void Update();
    void Render();
    ~Player();
};

#endif