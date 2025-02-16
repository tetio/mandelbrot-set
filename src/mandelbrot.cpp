#include <iostream>
#include <complex>

#include "mandelbrot.hpp"

void Mandelbrot::Draw() {
    idx = (idx + 1) % MAX_ITERATIONS;
    for (int x = 0; x < columns; x++) {
        for (int y = 0; y < rows; y++) {
            DrawRectangle(x, y, 1, 1, CalculateColor(pixel2point(x, y)));
        }
    }
}

void Mandelbrot::newRange(std::pair<double, double> rr, std::pair<double, double> ir) {
    realRange = rr;
    imagRange = ir;
}

std::complex<double> Mandelbrot::pixel2point(int x, int y) {
    double hOffset = (realRange.second - realRange.first) / columns;
    double vOffset = (imagRange.second - imagRange.first) / rows;

    return std::complex<double>{realRange.first + hOffset * double(x), imagRange.first + vOffset * double(y)};
}

Color Mandelbrot::CalculateColor(std::complex<double> c) {
    // Zn = (Zn-1)^2 + C
    // std::vector<std::complex<double>> z(MAX_ITERATIONS);
    std::vector<double> magnitude(MAX_ITERATIONS);
    std::complex<double> previousZ{ 0.0, 0.0 };
    std::complex<double> z{ 0.0, 0.0 };
    for (int i = 1; i < MAX_ITERATIONS; i++) {
        z = calculateZn(previousZ, c);
        previousZ = z;
        magnitude[i] = abs(z);
    }

    bool valueFromSet = true;
    int i = 1;
    while (i < MAX_ITERATIONS - 1 && magnitude[i] < 2) {
        i++;
    }
    if (i < MAX_ITERATIONS - 1) {
        valueFromSet = false;
    }
    // else
    // {
    //     std::cout << "Set!" << std::endl;
    // }

    if (valueFromSet) {
        return Color{ 0, 0, 0, 255 };
    } else {
        if (magnitude[idx] > 10e90) {
            return Color{ 200, 200, 200, 255 };
        } else if (magnitude[idx] > 10e80) {
            return Color{ 150, 150, 200, 255 };
        } else if (magnitude[idx] > 10e70) {
            return Color{ 100, 100, 200, 255 };
        } else if (magnitude[idx] > 10e60) {
            return Color{ 75, 75, 200, 255 };
        } else if (magnitude[idx] > 10e50) {
            return Color{ 60, 60, 200, 255 };
        } else if (magnitude[idx] > 10) {
            return Color{ 50, 50, 200, 255 };
        } else {
            return Color{ 10, 10, 200, 255 };
        }
    }
}

std::complex<double> Mandelbrot::calculateZn(std::complex<double> previousZ, std::complex<double> c) {
    return previousZ * previousZ + c;
}