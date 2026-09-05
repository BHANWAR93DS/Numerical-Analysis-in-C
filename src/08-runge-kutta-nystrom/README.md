# Experiment 08 — Runge-Kutta-Nyström

**Problem type:** second-order initial-value problem.

The implementation solves
```text
y'' = (1 + x^2)y
y(0) = 1,  y'(0) = 0
```

It follows the Runge-Kutta-Nyström formula used in the practical. The fourth stage is solved explicitly because the supplied stage definition contains (k_4) on its own right-hand side.

## Build and run

```bash
make exp08
./exp08
```
