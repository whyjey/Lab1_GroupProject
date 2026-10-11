
#ifndef ODE_H
#define ODE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef ODE_EXPORTS
#define ODE_API __declspec(dllexport)
#else
#define ODE_API __declspec(dllimport)
#endif

typedef double (*ODEFunction)(double, double);

ODE_API double euler(ODEFunction f, double x0, double y0, double h, int steps);
ODE_API double rungeKutta4(ODEFunction f, double x0, double y0, double h, int steps);
ODE_API double solve(ODEFunction f, double x0, double y0, double h, int steps, int method);
ODE_API double estimateError(ODEFunction f, double x0, double y0, double h, int steps);

#ifdef __cplusplus
}
#endif

#endif