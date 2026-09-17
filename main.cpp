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

    return 0;
}