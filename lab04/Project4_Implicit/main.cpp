#include "polynomials.h"
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
    
    double coeffs[] = {-2.0, 0.0, 1.0};
    int degree = 2;

    std::cout << "Polynomial value at x=3: "
              << evaluate(coeffs, degree, 3.0) << '\n';

    double derivativeCoeffs[2] = {};
    derivative(coeffs, degree, derivativeCoeffs);

    std::cout << "Derivative coefficients: "
              << derivativeCoeffs[0] << ", "
              << derivativeCoeffs[1] << '\n';

    std::cout << "Newton root: "
              << newtonRoot(coeffs, degree, 1.5, 100, 1e-6) << '\n';

    double roots[2] = {};
    int rootCount = findRoots(coeffs, degree, roots);

    std::cout << "Roots found: " << rootCount << '\n';
    for (int i = 0; i < rootCount && i < 2; i++) {
        std::cout << roots[i] << '\n';
    }


    return 0;
}