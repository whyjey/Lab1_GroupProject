
#include "ode.h"
#include <iostream>
#include <cmath>

double function(double x, double y) {
    return y;
}

int main() {
    double x0 = 0.0;
    double y0 = 1.0;
    double h = 0.1;
    int steps = 10;

    double resultEuler = euler(function, x0, y0, h, steps);
    double resultRK4 = rungeKutta4(function, x0, y0, h, steps);
    double error = estimateError(function, x0, y0, h, steps);

    std::cout << "Euler result: " << resultEuler << '\n';
    std::cout << "Runge-Kutta 4 result: " << resultRK4 << '\n';
    std::cout << "Exact result: " << std::exp(1.0) << '\n';
    std::cout << "Estimated error: " << error << '\n';

    return 0;
}