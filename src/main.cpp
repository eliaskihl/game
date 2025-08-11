#include <raylib.h>
#include "ball.h"

int main() 
{
    const Color darkGreen = {20, 200, 133, 255};
    
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;
    
    Ball ball;
    Ball ball2;
    ball2 = Ball(10,10,2,2,10);
    
    InitWindow(screenWidth, screenHeight, "This is the title.");
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        ball.Update();
        ball2.Update();
        
        BeginDrawing();
            ClearBackground(darkGreen);
            ball.Draw();
            ball2.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}