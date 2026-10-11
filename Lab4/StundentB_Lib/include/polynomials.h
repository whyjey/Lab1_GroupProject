#pragma once

#ifdef STUDENTB_EXPORTS
#define STUDENTB_API extern "C" __declspec(dllexport)
#else
#define STUDENTB_API extern "C" __declspec(dllimport)
#endif

STUDENTB_API double evaluate(const double* coeffs, int degree, double x);

STUDENTB_API void derivative(const double* coeffs, int degree, double* out_coeffs);

STUDENTB_API double newtonRoot(const double* coeffs, int degree, double initial_guess, int max_iter, double tol);

STUDENTB_API int findRoots(const double* coeffs, int degree, double* out_roots);