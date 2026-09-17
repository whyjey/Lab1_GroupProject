#include <iostream>
#include <memory>
#include <iomanip>

#include "shared_types.h"

ResultPtr solveStudentA(InputDataPtr input);
ResultPtr solveStudentB(InputDataPtr input);

int main()
{
    auto input = std::make_shared<const InputData>();

    auto resultA = solveStudentA(input);

    const auto& [xValues, yValues, finalValue, error, executionTime] = *resultA;

    std::cout << "Student A - Euler method\n\n";
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "x\t\ty\n";
    for (std::size_t i = 0; i < xValues.size(); ++i)
    {
        std::cout << xValues[i] << "\t\t" << yValues[i] << '\n';
    }
    std::cout << "\nFinal value: " << finalValue << '\n';
    std::cout << "Error: " << error << '\n';
    std::cout << "Execution time: " << executionTime << " microseconds\n";

    std::cout << "--------------------------------------------------\n\n";

    auto resultB = solveStudentB(input);
    const auto& [
        xValuesB, yValuesB,
        finalValueB, errorB, executionTimeB
    ] = *resultB;

    std::cout << "Student B - Runge-Kutta 4 method\n\n";
    std::cout << "x\t\ty\n";
    for (std::size_t i = 0; i < xValuesB.size(); ++i)
    {
        std::cout << xValuesB[i] << "\t\t" << yValuesB[i] << '\n';
    }
    std::cout << "\nFinal value: " << finalValueB << '\n';
    std::cout << "Error: " << errorB << '\n';
    std::cout << "Execution time: " << executionTimeB << " microseconds\n";

    return 0;
}