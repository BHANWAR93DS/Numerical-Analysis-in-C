# Experiment 2 — Finite Difference Method (Second Kind)

Solves `y'' - y = x` with derivative boundary conditions `y'(0)=0`, `y'(1)=1`. Central finite differences are combined with ghost-point endpoint equations and the Thomas algorithm.

Compile: `gcc -std=c11 -Wall -Wextra main.c -o exp02`
