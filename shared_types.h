#pragma once

#include <memory>

struct InputData
{
    // Параметри задачі
};

struct Result
{
    // Характеристики результату
};

using InputDataPtr = std::shared_ptr<const InputData>;
using ResultPtr = std::unique_ptr<Result>;