#pragma once
#include <raylib.h>
#include <vector>
#include <complex>


class Mandelbrot {
public:
    Mandelbrot(int rows, int columns, std::pair<double, double> real, std::pair<double, double> imag) : rows(rows), columns(columns), realRange(real), imagRange(imag) {};
    void Draw();
    void newRange(std::pair<double, double> real, std::pair<double, double> imag);
private:
    std::complex<double> pixel2point(int x, int y);
    Color CalculateColor(std::complex<double> c);
    std::complex<double> calculateZn(std::complex<double> previousZ, std::complex<double> c);
    int rows;
    int idx = 0;
    int columns;
    const int MAX_ITERATIONS = 16;
    std::pair<double, double> realRange;
    std::pair<double, double> imagRange;
};