// #include "raylib.h" //-lraylib -lGL -lm -lpthread -ldl -lrt -lX11
// #include "../include/player.h"
// #include "../include/axe.h"

#include "../include/game.h"

int main(){

    SetupWindow();

    // ========== initialization of game variables
    Player player{};
    Axe axe{};
    Goal goal{};

    bool new_level{false};
    bool game_over{false};

    int lvl_count{1};
    int prev_lvl{};
    

    //main game loop
    while(!WindowShouldClose()){
       
       if(lvl_count != prev_lvl){
            SetLevel(player,axe,lvl_count);
            prev_lvl = lvl_count;
        }

      
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
            DisplayGameOver(lvl_count);
            game_over = true;
        } 
        else if(CollisionDetection(*goal.collider_goal,player)){
            lvl_count++;
        }
        else {
            DisplayHUD(lvl_count);
            player.Render();
            axe.Render();
            goal.Render();
        }
    
        EndDrawing();

        // }
     }
    return 0;
}