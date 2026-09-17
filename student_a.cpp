#include "shared_types.h"

#include <cmath>
#include <chrono>
#include <algorithm>

double f(double x, double y)
{
    return x + y;
}

double exactSolution(double x)
{
    return 2.0 * std::exp(x) - x - 1.0;
}

ResultPtr solveStudentA(InputDataPtr input)
{
    auto result = std::make_unique<Result>();

    const auto start = std::chrono::high_resolution_clock::now();

    double x = input->x0;
    double y = input->y0;

    result->xValues.push_back(x);
    result->yValues.push_back(y);

    while (x < input->xEnd)
    {
        double step = std::min(input->h, input->xEnd - x);

        y = y + step * f(x, y);
        x = x + step;

        result->xValues.push_back(x);
        result->yValues.push_back(y);
    }

    result->finalValue = y;
    result->error = std::abs(y - exactSolution(input->xEnd));

    const auto end = std::chrono::high_resolution_clock::now();

    result->executionTime =
        std::chrono::duration<double, std::micro>(end - start).count();

    return result;
}