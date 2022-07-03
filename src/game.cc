#include "../include/game.h"


bool CollisionDetection(Collider& collider, Player& player){
        return
                        (collider.bottom_corner >= player.collider_player->upper_corner) && 
                        (collider.upper_corner <= player.collider_player->bottom_corner) && 
                        (collider.left_corner <= player.collider_player->right_corner) && 
                        (collider.right_corner >= player.collider_player->left_corner);
}

void SetLevel(Player& player, Axe& axe, int level_index){
    player.ResetPoint();
    axe.IncreaseSpeed(level_index);
}

void DisplayGameOver(int& value){
    DrawText("Game Over", GetScreenWidth()/2 - 40,GetScreenHeight()/2 - 10,20,RED);
    DrawText(TextFormat("Score: %i",value), GetScreenWidth()/2 - 40,GetScreenHeight()/2 + 10,20,GREEN);
    DrawText("R - Restart Game", GetScreenWidth()/2 - 40,GetScreenHeight()/2 + 30,20,RED);
}

void DisplayHUD(int& value){
    DrawText(TextFormat("Level: %i",value),0 + 20/2,GetScreenHeight() - 20,20,GRAY);
}

void SetupWindow(){
    //Doom 95 running at 640x480 resolution.640x480 resolution.
    int width{640};
    int height{480};
    InitWindow(width,height,"Avoid It!");
   
    SetTargetFPS(60);
}

void RestartGame(int& lvl, bool& game_state){
    if(IsKeyDown(KEY_R)){

        lvl = 1;
        game_state = false;
    }
}