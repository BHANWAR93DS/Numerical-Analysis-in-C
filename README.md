# Numerical Analysis in C

A collection of numerical methods implemented in **C**, organized as a practical study of boundary-value and initial-value problems.

The repository focuses on translating mathematical formulations into clear, standalone C programs.

## Experiments

| # | Method | Problem |
|---|---|---|
| 01 | Finite Difference Method — First Kind | Boundary Value Problem |
| 02 | Finite Difference Method — Second Kind | Boundary Value Problem |
| 03 | Finite Difference Method — Third Kind | Boundary Value Problem |
| 04 | Numerov Method | Boundary Value Problem |
| 05 | Euler Method | First-Order IVP System |
| 06 | Euler-Cauchy Method | First-Order IVP System |
| 07 | Runge-Kutta Fourth Order | First-Order IVP System |
| 08 | Runge-Kutta-Nyström | Second-Order IVP |
| 09 | Shooting Method + Euler | Second-Order BVP |
| 10 | Shooting Method + Euler-Cauchy | Second-Order BVP |
| 11 | Shooting Method + Runge-Kutta Fourth Order | Second-Order BVP |

## Repository Structure

```text
.
├── README.md
├── LICENSE
├── .gitignore
├── Makefile
└── src/
    ├── 01-finite-difference-first-kind/
    ├── 02-finite-difference-second-kind/
    ├── 03-finite-difference-third-kind/
    ├── 04-numerov-method/
    ├── 05-euler-method/
    ├── 06-euler-cauchy-method/
    ├── 07-runge-kutta-fourth-order/
    ├── 08-runge-kutta-nystrom/
    ├── 09-shooting-euler/
    ├── 10-shooting-euler-cauchy/
    └── 11-shooting-runge-kutta/
```

Each experiment contains a standalone `main.c`. Selected experiments also include a short method README.

## Building

GCC with C11 support is recommended.

Build one experiment:

```bash
make exp07
./exp07
```

Build all experiments:

```bash
make all
```

The generated executables are ignored by Git.

You can also compile any program directly:

```bash
gcc -std=c11 -Wall -Wextra -O2 src/07-runge-kutta-fourth-order/main.c -o exp07
```

## Numerical Methods Covered

- Finite-difference discretization of BVPs
- Thomas algorithm for tridiagonal systems
- Numerov method
- Euler method
- Euler-Cauchy method
- Classical fourth-order Runge-Kutta method
- Runge-Kutta-Nyström method
- Shooting method for second-order BVPs

## Scope

This repository is intended as a practical/learning resource. The programs are kept small and self-contained so that the connection between the mathematical method and its C implementation remains easy to follow.

## Author

**Bhanwar Lal**  
M.Sc. Mathematics
