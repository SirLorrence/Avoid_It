#include "../include/player.h"


Player::Player(int init_x,int init_y){
    position.x = init_x;
    position.y = init_y;
}

void Player::Update(){

    if(IsKeyDown(KEY_D) && position.x < GetScreenWidth()) position.x += speed;
    if(IsKeyDown(KEY_A) && position.x > 0) position.x -= speed;

    // the inverse with this library
    if(IsKeyDown(KEY_W) && position.y > 0) position.y -= speed; 
    if(IsKeyDown(KEY_S) && position.y < GetScreenHeight()) position.y += speed;
}

void Player::Render(){

    DrawCircle(position.x,position.y,radius,BLUE);
    
}

Player::~Player() {};
