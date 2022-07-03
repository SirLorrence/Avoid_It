#include "../include/goal.h"

Goal::Goal(){
    collider.length = length;
    collider_goal = &collider;
    position.x = GetScreenWidth() - length;
    position.y = GetScreenHeight()/2 - (length/2);
    collider.UpdateCollider(position.x,position.y); // can be initialized here (called once) because it not going to moving
}

void Goal::Render(){
    DrawRectangle(position.x,position.y,length,length,GREEN);
}

Goal::~Goal(){}