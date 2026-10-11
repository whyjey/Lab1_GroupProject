#include <iostream>
#include "ode.h"

double testFunction(double x, double y) {
    return x + y;
}

int main() {
    std::cout << "=== Implicit Linking ===" << std::endl;

    double result = euler(testFunction, 0.0, 1.0, 0.1, 10);
    
    std::cout << "Result from euler(): " << result << std::endl;
    std::cout << "Mission Accomplished!" << std::endl;
    
    return 0;
}