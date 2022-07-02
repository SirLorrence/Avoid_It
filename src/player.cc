#include "../include/player.h"

Player::Player(){
    collider.radius = kRadius; // set collider radius since player is an circle 
    radius = &kRadius;
    collider_player = &collider;
} 

void Player::SetPoint(int x,int y){
    position.x = x;
    position.y = y;
}
void Player::Update(){

    //collision check
    
    if(IsKeyDown(KEY_D) && position.x < GetScreenWidth()) position.x += speed;
    if(IsKeyDown(KEY_A) && position.x > 0) position.x -= speed;

    // the inverse with this library
    if(IsKeyDown(KEY_W) && position.y > 0) position.y -= speed; 
    if(IsKeyDown(KEY_S) && position.y < GetScreenHeight()) position.y += speed;


    //collision calculation goes here
    collider.UpdateCollider(position.x,position.y);

}

void Player::Render(){
    DrawCircle(position.x,position.y,kRadius,BLUE);
}

Player::~Player() {}
