#include <iostream>
#include <memory>

#include "shared_types.h"

ResultPtr solveStudentA(InputDataPtr input);
ResultPtr solveStudentB(InputDataPtr input);

int main()
{
    auto input = std::make_shared<InputData>();

    auto resultA = solveStudentA(input);
    auto resultB = solveStudentB(input);

    std::cout << "Lab1_GroupProject started successfully.\n";

    return 0;
}