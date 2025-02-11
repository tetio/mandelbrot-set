#include <iostream>
#include <complex>

#include "mandelbrot.hpp"

void Mandelbrot::Draw()
{
    for (int x = 0; x < columns; x++)
    {
        for (int y = 0; y < rows; y++)
        {
            DrawRectangle(x, y, 1, 1, CalculateColor(pixel2point(x, y)));
        }
    }
}

std::complex<double> Mandelbrot::pixel2point(int x, int y)
{
    double hOffset = (realRange.second - realRange.first) / columns;
    double vOffset = (imagRange.second - imagRange.first) / rows;

    return std::complex<double>{realRange.first + hOffset * double(x), imagRange.first + vOffset * double(y)};
}

Color Mandelbrot::CalculateColor(std::complex<double> c)
{
    // Zn = (Zn-1)^2 + C
    // std::vector<std::complex<double>> z(MAX_ITERATIONS);
    std::vector<double> magnitude(MAX_ITERATIONS);
    std::complex<double> previousZ{0.0, 0.0};
    std::complex<double> z{0.0, 0.0};
    for (int i = 1; i < MAX_ITERATIONS; i++)
    {
        z = calculateZn(previousZ, c);
        previousZ = z;
        magnitude[i] = abs(z);
    }

    bool valueFromSet = true;
    int i = 1;
    while (i < MAX_ITERATIONS - 1 && magnitude[i] < 10)
    {
        i++;
    }
    if (i < MAX_ITERATIONS - 1)
    {
        valueFromSet = false;
    }
    // else
    // {
    //     std::cout << "Set!" << std::endl;
    // }

    // if (std::abs(z[5]) > std::abs(z[4]) && std::abs(z[4]) > std::abs(z[3]) && std::abs(z[3]) > std::abs(z[2]) && std::abs(z[2]) > std::abs(z[1]) && std::abs(z[1]) > std::abs(z[0])) {
    //     valueFromSet = false;
    // }
    return valueFromSet ? Color{0, 0, 0, 255} : Color{200, 200, 200, 255};
}

std::complex<double> Mandelbrot::calculateZn(std::complex<double> previousZ, std::complex<double> c)
{
    return previousZ * previousZ + c;
}