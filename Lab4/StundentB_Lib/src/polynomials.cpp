#include "polynomials.h"
#include <cmath>

extern "C" {

double evaluate(const double* coeffs, int degree, double x) {
    double result = 0;
    for (int i = 0; i <= degree; ++i) {
        result += coeffs[i] * std::pow(x, i);
    }
    return result;
}

void derivative(const double* coeffs, int degree, double* out_coeffs) {
    if (degree < 1) return;
    for (int i = 1; i <= degree; ++i) {
        out_coeffs[i - 1] = coeffs[i] * i;
    }
}

double newtonRoot(const double* coeffs, int degree, double initial_guess, int max_iter, double tol) {
    return initial_guess;
}

int findRoots(const double* coeffs, int degree, double* out_roots) {
    return 0;
}

}