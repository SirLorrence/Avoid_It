#include "../include/axe.h"

Axe::Axe(){
    position.x = GetScreenWidth()/2;
    position.y = 0;

    collider.length = length;
    collider_axe = &collider;
}
void Axe::IncreaseSpeed(int multiplier){
    speed = 5 * multiplier;
}

void Axe::Update(){
    position.y += speed;
    if(position.y > GetScreenHeight() - length || position.y < 0)
        speed *= -1;

    collider.UpdateCollider(position.x,position.y);
}

void Axe::Render(){
    DrawRectangle(position.x,position.y,length,length, RED);
}

Axe::~Axe(){}