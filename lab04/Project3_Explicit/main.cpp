
#include <iostream>
#include <windows.h>

using namespace std;

using ODEFunction = double (*)(double, double);
using RK4Function = double (*)(ODEFunction, double, double, double, int);

using EvaluateFunction = double (*)(const double*, int, double);
using DerivativeFunction = void (*)(const double*, int, double*);
using NewtonRootFunction = double (*)(const double*, int, double, int, double);
using FindRootsFunction = int (*)(const double*, int, double*);

double function(double x, double y) {
    return y;
}

int main() {
    HMODULE odeLibrary = LoadLibraryA("libode.dll");
    HMODULE polyLibrary = LoadLibraryA("libStudentBLib.dll");

    if (odeLibrary == nullptr || polyLibrary == nullptr) {
        cout << "Failed to load DLL\n";
        if (odeLibrary) FreeLibrary(odeLibrary);
        if (polyLibrary) FreeLibrary(polyLibrary);
        return 1;
    }

    auto rungeKutta4 = reinterpret_cast<RK4Function>(
        GetProcAddress(odeLibrary, "rungeKutta4")
    );

    auto evaluate = reinterpret_cast<EvaluateFunction>(
        GetProcAddress(polyLibrary, "evaluate")
    );

    auto derivative = reinterpret_cast<DerivativeFunction>(
        GetProcAddress(polyLibrary, "derivative")
    );

    auto newtonRoot = reinterpret_cast<NewtonRootFunction>(
        GetProcAddress(polyLibrary, "newtonRoot")
    );

    auto findRoots = reinterpret_cast<FindRootsFunction>(
        GetProcAddress(polyLibrary, "findRoots")
    );

    if (!rungeKutta4 || !evaluate || !derivative ||
        !newtonRoot || !findRoots) {
        cout << "Failed to find function\n";
        FreeLibrary(odeLibrary);
        FreeLibrary(polyLibrary);
        return 1;
    }

    double result = rungeKutta4(function, 0.0, 1.0, 0.1, 10);
    cout << "Runge-Kutta 4 result: " << result << '\n';

    double coeffs[] = {-2.0, 0.0, 1.0};
    int degree = 2;

    cout << "Polynomial value at x=3: "
         << evaluate(coeffs, degree, 3.0) << '\n';

    double derivativeCoeffs[2] = {};
    derivative(coeffs, degree, derivativeCoeffs);

    cout << "Derivative coefficients: "
         << derivativeCoeffs[0] << ", "
         << derivativeCoeffs[1] << '\n';

    cout << "Newton root: "
         << newtonRoot(coeffs, degree, 1.5, 100, 1e-6) << '\n';

    double roots[2] = {};
    int rootCount = findRoots(coeffs, degree, roots);

    cout << "Roots found: " << rootCount << '\n';
    for (int i = 0; i < rootCount && i < 2; i++) {
        cout << roots[i] << '\n';
    }

    FreeLibrary(odeLibrary);
    FreeLibrary(polyLibrary);

    return 0;
}
