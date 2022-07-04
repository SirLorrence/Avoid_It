#ifndef GOAL_H
#define GOAL_H
#include "raylib.h"
#include "../include/collider.h"

class Goal{
private:
    int length{75};
    Collider collider;
    Vector2 position;
    
public:
    Goal();
    Collider* collider_goal;
    void Render();
    ~Goal();
};
#endif

// //trying out -- doesn't work in the way i thought it would
//  better to just create it's own class
// Goal::Goal(){
//     collider.length = length;
// }

// void Goal::Render(){
//     DrawRectangle(GetScreenWidth() - length,GetScreenHeight()/2,length,length,GREEN);
// }

// Goal::~Goal(){}


