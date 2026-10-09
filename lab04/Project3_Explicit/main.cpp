
#include <windows.h>
#include <iostream>

using ODEFunction = double (*)(double, double);

using RK4Function = double (*)(ODEFunction, double, double, double, int);

double function(double x, double y) {
    return y;
}

int main() {
    HMODULE library = LoadLibraryA("../Project2_Shared/sdk/bin/libode.dll");

    if (library == nullptr) {
        std::cout << "Failed to load DLL\n";
        return 1;
    }

    auto rungeKutta4 = reinterpret_cast<RK4Function>(
        GetProcAddress(library, "rungeKutta4")
    );

    if (rungeKutta4 == nullptr) {
        std::cout << "Failed to find function\n";
        FreeLibrary(library);
        return 1;
    }

    double result = rungeKutta4(function, 0.0, 1.0, 0.1, 10);

    std::cout << "Runge-Kutta 4 result: " << result << '\n';

    FreeLibrary(library);
    return 0;
}