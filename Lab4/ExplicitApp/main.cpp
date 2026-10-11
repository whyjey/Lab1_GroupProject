#include <iostream>
#include <windows.h>

typedef double (*ODEFunction)(double, double);
typedef double (*EulerFunc)(ODEFunction, double, double, double, int);

double testFunction(double x, double y) {
    return x + y;
}

int main() {
    std::cout << "=== Explicit Linking ===" << std::endl;

    HMODULE hLib = LoadLibrary(TEXT("libode.dll"));
    if (!hLib) {
        std::cerr << "ERROR: Failed to load libode.dll" << std::endl;
        return 1;
    }
    std::cout << "[+] DLL successfully loaded." << std::endl;

    auto eulerFunc = reinterpret_cast<EulerFunc>(GetProcAddress(hLib, "euler"));

    if (eulerFunc) {
        double result = eulerFunc(testFunction, 0.0, 1.0, 0.1, 10);
        std::cout << "Result from euler(): " << result << std::endl;
    } else {
        std::cerr << "[-] ERROR: Function 'euler' not found!" << std::endl;
    }

    FreeLibrary(hLib);
    std::cout << "[+] DLL unloaded." << std::endl;

    return 0;
}