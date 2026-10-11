
#ifndef ODE_H
#define ODE_H

using ODEFunction = double (*)(double, double);

double euler(ODEFunction f, double x0, double y0, double h, int steps);
double rungeKutta4(ODEFunction f, double x0, double y0, double h, int steps);
double solve(ODEFunction f, double x0, double y0, double h, int steps, int method);
double estimateError(ODEFunction f, double x0, double y0, double h, int steps);

#endif