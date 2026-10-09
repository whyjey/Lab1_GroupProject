
#include "ode.h"
#include <iostream>

double function(double x, double y) {
    return y;
}

int main() {
    double result = rungeKutta4(function, 0.0, 1.0, 0.1, 10);
    std::cout << "Normal result: " << result << '\n';

    double nullResult = rungeKutta4(nullptr, 0.0, 1.0, 0.1, 10);
    std::cout << "Null callback test: " << nullResult << '\n';

    double invalidStep = rungeKutta4(function, 0.0, 1.0, 0.0, 10);
    std::cout << "Zero step size test: " << invalidStep << '\n';

    double invalidSteps = rungeKutta4(function, 0.0, 1.0, 0.1, 0);
    std::cout << "Zero steps test: " << invalidSteps << '\n';

    double invalidMethod = solve(function, 0.0, 1.0, 0.1, 10, 2);
    std::cout << "Unknown method test: " << invalidMethod << '\n';
        double negativeStep = rungeKutta4(function, 0.0, 1.0, -0.1, 10);
    std::cout << "Negative step size test: " << negativeStep << '\n';

    double negativeSteps = rungeKutta4(function, 0.0, 1.0, 0.1, -10);
    std::cout << "Negative steps count test: " << negativeSteps << '\n';

    return 0;
}