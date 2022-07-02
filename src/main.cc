#include "raylib.h" //-lraylib -lGL -lm -lpthread -ldl -lrt -lX11


//pointer references... i understand now
void UserInput(int& x, int& y, int& speed){
    
    if(IsKeyDown(KEY_D) && x < GetScreenWidth()) x += speed;
    if(IsKeyDown(KEY_A) && x > 0) x -= speed;

    // the inverse with this library
    if(IsKeyDown(KEY_W) && y > 0) y -= speed; 
    if(IsKeyDown(KEY_S) && y < GetScreenHeight()) y += speed;
}

void Axe(int& y, int& speed){
    y += speed;
    if(y > GetScreenHeight() - 50 || y < 0) // hard code the size of the rectangle (50)
        speed *= -1;
}


int main(){


    //create window
    //Doom 95 running at 640x480 resolution.640x480 resolution.
    int width{640};
    int height{480  };
    InitWindow(width,height,"Hello!");




    int initX{width/2};
    int initY{height/2};

    int xCoord{initX};
    int yCoord{initY};

    int Axe_coord{0};
 
    int moveSpeed{10};
    int axeSpeed{5};


    int circleRadius{25};
    int axeLength{50};

    /* ========================== Corrdinates for edge
    
        1x------------2x
        |              |
        |              |
        |      c       |
        |              |
        |              |
        3x------------4x
       LEFT = 1x = 1x - c
       RIGHT = 2x = 2x + c
       UPPER = 2x
       BOTTOM = 4x  

    */

    // ========= collision
    // circle

    int lc_circle{xCoord - circleRadius};
    int rc_circle{xCoord + circleRadius};
    int uc_circle{yCoord - circleRadius};
    int bc_circle{yCoord + circleRadius};


    //axe

    int lc_axe{300};
    int rc_axe{300 + axeLength};
    int uc_axe{Axe_coord};
    int bc_axe{Axe_coord + axeLength};

    SetTargetFPS(60);
    //main game loop
    while(!WindowShouldClose()){
        if(true)
        {
            DrawText("Game Over", initX/2,initY,20,RED);
        }
        //Update Logic
        UserInput(xCoord,yCoord, moveSpeed);
        Axe(Axe_coord,axeSpeed);                

        //Update Render        
        BeginDrawing(); //creates an double buffer (raylib magic)
        ClearBackground(WHITE);

        // DrawCircle(xCoord,yCoord, circleRadius, BLUE);
        // DrawRectangle(300, Axe_coord,50,axeLength,RED);

        EndDrawing();
     }


    return 0;
}