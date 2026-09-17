#pragma once

#include <memory>
#include <vector>

struct InputData
{
    double x0 = 0.0;
    double y0 = 1.0;
    double xEnd = 1.0;
    double h = 0.1;
};

struct Result
{
    std::vector<double> xValues;
    std::vector<double> yValues;
    double finalValue;
    double error;
    double executionTime;
};

using InputDataPtr = std::shared_ptr<const InputData>;
using ResultPtr = std::unique_ptr<Result>;