#include <raylib.h>
#include <iostream>
#include "mandelbrot.hpp"

int main()
{
    constexpr Color darkGray = {22, 22, 22, 255};

    constexpr int screenWidth = 750;
    constexpr int screenHeight = 750;
    constexpr int CELL_SIZE = 1;

    InitWindow(screenWidth, screenHeight, "Mandelbrot Set");
    SetTargetFPS(1);

    Mandelbrot mandelbrot = Mandelbrot{screenHeight / CELL_SIZE, screenWidth / CELL_SIZE, {-2.5, 1.5}, {-2.0, 2.0}};

    while (!WindowShouldClose())
    {
        // 1 - Event Handling

        // 2 - Update State

        // 3 - Drawing
        BeginDrawing();
            ClearBackground(darkGray);
            mandelbrot.Draw();
        EndDrawing();
    }

    CloseWindow();
}