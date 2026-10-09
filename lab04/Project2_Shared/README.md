
# ODE Solver SDK

## Purpose

This library numerically solves ordinary differential equations
of the form y' = f(x, y).

## Files

- include/ode.h — function declarations and API types.
- bin/libode.dll — dynamic library.
- lib/libode.dll.a — GCC import library.

## API

All functions use the C ABI (`extern "C"`).

```cpp
typedef double (*ODEFunction)(double, double);

double euler(ODEFunction f, double x0, double y0, double h, int steps);
double rungeKutta4(ODEFunction f, double x0, double y0, double h, int steps);
double solve(ODEFunction f, double x0, double y0, double h, int steps, int method);
double estimateError(ODEFunction f, double x0, double y0, double h, int steps);
```

## Parameters

- `f` — function defining y' = f(x, y).
- `x0`, `y0` — initial coordinates.
- `h` — step size; must be positive.
- `steps` — number of steps; must be positive.
- `method` — 1 for Euler, 4 for Runge-Kutta 4.

## Return values

The functions return the computed y value.
`estimateError` returns the Runge-Kutta error estimate.

Invalid inputs return `0.0`. This value is ambiguous because zero
can also be a valid numerical result.

## Limitations

- The library does not provide a separate error status.
- The callback `f` must be valid and must not crash.
- Very large `steps` values can cause excessive computation.
- Numerical results depend on the selected step size.