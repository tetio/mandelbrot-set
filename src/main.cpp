#include <raylib.h>
#include <iostream>
#include "mandelbrot.hpp"

int main()
{
    constexpr Color darkGray = {22, 22, 22, 255};

    constexpr int screenWidth = 750;
    constexpr int screenHeight = 750;

    InitWindow(screenWidth, screenHeight, "Mandelbrot Set");
    SetTargetFPS(60);

    Mandelbrot mandelbrot = Mandelbrot{screenHeight, screenWidth, {-2.25, 1.00}, {-1.50, 1.50}};

    while (!WindowShouldClose())
    {
        // 1 - Event Handling
        // if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        //     Vector2 pos =  GetMousePosition();
        //     Vector2 distance2center = Vector2{pos.x - screenWidth / 2, pos.y - screenHeight /2 };
        //     double dh = abs(1.25 - (2.25));
        //     double dv = abs(-1.75 - (1.75));
        //     Vector2 newReal = (-2.25) + dh/2
        //     mandelbrot.setNewRange(); // = Mandelbrot{screenHeight, screenWidth, {-2.25, 1.25}, {-1.75, 1.75}};
        // }
        // 2 - Update State

        // 3 - Drawing
        BeginDrawing();
        ClearBackground(darkGray);
        mandelbrot.Draw();
        EndDrawing();
    }

    CloseWindow();
}

// #include "raylib.h"

// int main(void)
// {
//     InitWindow(800, 450, "raylib [core] example - basic window");

//     while (!WindowShouldClose())
//     {
//         BeginDrawing();
//             ClearBackground(RAYWHITE);
//             DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
//         EndDrawing();
//     }

//     CloseWindow();

//     return 0;
// }