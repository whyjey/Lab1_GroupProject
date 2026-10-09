
#include "ode.h"
#include <stdexcept>

double euler(ODEFunction f, double x0, double y0, double h, int steps) {
    if (f == nullptr || h <= 0 || steps <= 0)
        throw std::invalid_argument("Invalid input");

    double x = x0;
    double y = y0;

    for (int i = 0; i < steps; i++) {
        y += h * f(x, y);
        x += h;
    }

    return y;
}

double rungeKutta4(ODEFunction f, double x0, double y0, double h, int steps) {
    if (f == nullptr || h <= 0 || steps <= 0)
        throw std::invalid_argument("Invalid input");

    double x = x0;
    double y = y0;

    for (int i = 0; i < steps; i++) {
        double k1 = f(x, y);
        double k2 = f(x + h / 2, y + h * k1 / 2);
        double k3 = f(x + h / 2, y + h * k2 / 2);
        double k4 = f(x + h, y + h * k3);

        y += h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x += h;
    }

    return y;
}

double solve(ODEFunction f, double x0, double y0, double h, int steps, int method) {
    if (method == 1)
        return euler(f, x0, y0, h, steps);

    if (method == 4)
        return rungeKutta4(f, x0, y0, h, steps);

    throw std::invalid_argument("Unknown method");
}

double estimateError(ODEFunction f, double x0, double y0, double h, int steps) {
    double full = rungeKutta4(f, x0, y0, h, steps);
    double half = rungeKutta4(f, x0, y0, h / 2, steps * 2);

    return (half - full) / 15.0;
}