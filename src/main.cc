#include "raylib.h" //-lraylib -lGL -lm -lpthread -ldl -lrt -lX11
#include "../include/player.h"
#include "../include/axe.h"


bool CollisionDetection(Collider& collider, Player& player){
        return
                        (collider.bottom_corner >= player.collider_player->upper_corner) && 
                        (collider.upper_corner <= player.collider_player->bottom_corner) && 
                        (collider.left_corner <= player.collider_player->right_corner) && 
                        (collider.right_corner >= player.collider_player->left_corner);
}


int main(){
    //create window
    //Doom 95 running at 640x480 resolution.640x480 resolution.
    int width{640};
    int height{480};
    InitWindow(width,height,"Hello!");


    // game variables
    bool game_over{false};

    // initialization 
    Player player{};
    Axe axe{};
    

    int initY{height/2};
    int initX{0 + (int)*player.radius};

    player.SetPoint(initX,initY);

    SetTargetFPS(60);
    //main game loop
    while(!WindowShouldClose()){
      
      
        //================= Update Logic
        if(!game_over){
            player.Update();
            axe.Update();
        }
        

        //================= Update Render        
        BeginDrawing(); //creates an double buffer (raylib magic)
        ClearBackground(WHITE);
        
        //if the player collides with the axe, game is over
        if(CollisionDetection(*axe.collider_axe,player)){ 
            //dereferences~ axe collider ^^
            DrawText("Game Over", GetScreenWidth()/2,GetScreenHeight()/2,20,RED);
            game_over = true;
        } else {
            player.Render();
            axe.Render();
        }
    
        EndDrawing();

        // }
     }
    return 0;
}