# Numerical Analysis in C

A structured collection of numerical methods implemented in **C**, based on an M.Sc. Mathematics practical study. The repository connects mathematical formulations with algorithms and executable numerical implementations.

## Contents

| # | Method | Problem type |
|---|---|---|
| 01 | Finite Difference Method | BVP — first kind |
| 02 | Finite Difference Method | BVP — second kind |
| 03 | Finite Difference Method | BVP — third kind |
| 04 | Numerov Method | BVP |
| 05 | Euler Method | First-order IVP system |
| 06 | Euler-Cauchy Method | First-order IVP system |
| 07 | Runge-Kutta 4th Order | First-order IVP system |
| 08 | Runge-Kutta-Nyström | Second-order IVP |
| 09 | Shooting Method + Euler | Second-order BVP |
| 10 | Shooting Method + Euler-Cauchy | Second-order BVP |
| 11 | Shooting Method + RK4 | Second-order BVP |

## Repository Structure

```text
.
├── README.md
├── LICENSE
├── .gitignore
├── Makefile
├── src/
│   ├── 01-finite-difference-first-kind/
│   ├── 02-finite-difference-second-kind/
│   ├── 03-finite-difference-third-kind/
│   ├── 04-numerov-method/
│   ├── 05-euler-method/
│   ├── 06-euler-cauchy-method/
│   ├── 07-runge-kutta-fourth-order/
│   ├── 08-runge-kutta-nystrom/
│   ├── 09-shooting-euler/
│   ├── 10-shooting-euler-cauchy/
│   └── 11-shooting-runge-kutta/
├── latex/
│   └── experiments-07-11.tex
└── docs/
    └── Numerical-Analysis-Practical.pdf
```

## How to Compile

A C compiler such as GCC is required.

Compile an individual experiment:

```bash
gcc src/07-runge-kutta-fourth-order/main.c -o rk4
./rk4
```

Or use the Makefile:

```bash
make exp07
```

## Mathematical Scope

The implementations cover:

- Boundary value problems
- Initial value problems
- Finite-difference discretization
- Tridiagonal linear systems
- Thomas algorithm
- Numerov integration
- Euler and Euler-Cauchy methods
- Classical fourth-order Runge-Kutta
- Runge-Kutta-Nyström
- Shooting methods

## Academic Documentation

The original practical work is being organized alongside its LaTeX source and generated PDF so that the repository preserves both the **mathematical derivation** and the **C implementation**.

## Notes

The source material contains classroom/practical implementations. During repository cleanup, code is being separated into standalone C programs and obvious portability issues are being addressed without changing the intended numerical method.

**Author:** Bhanwar Lal — M.Sc. Mathematics
