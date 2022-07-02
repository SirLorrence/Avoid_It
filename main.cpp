#include "raylib.h" //-lraylib -lGL -lm -lpthread -ldl -lrt -lX11
int main(){


    int width{350};
   

    InitWindow(width,200,"Hello!");
    while(!WindowShouldClose()){
                
        BeginDrawing();
        ClearBackground(WHITE); //frame buffer 
        EndDrawing();
    }

    return 0;
}