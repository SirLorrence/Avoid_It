#include "raylib.h" //-lraylib -lGL -lm -lpthread -ldl -lrt -lX11


void Input(int& x, int& y, int speed){
    if(IsKeyDown(KEY_D)) x += speed;
    if(IsKeyDown(KEY_A)) x -= speed;

    // the inverse with this library
    if(IsKeyDown(KEY_W)) y -= speed; 
    if(IsKeyDown(KEY_S)) y += speed;
}

int main(){

    //create window
    int width{350};
    int height{350};
    InitWindow(width,height,"Hello!");



    int initX{width/2};
    int initY{height/2};

    int xCoord{initX};
    int yCoord{initY};

    int moveSpeed{10};


    SetTargetFPS(60);
    //main game loop
    while(!WindowShouldClose()){
                
        BeginDrawing(); //creates an double buffer (raylib magic)
        ClearBackground(WHITE); 


        DrawCircle(xCoord,yCoord, 15.0f, BLUE);

        Input(xCoord,yCoord, moveSpeed);

        EndDrawing();
    }

    return 0;
}