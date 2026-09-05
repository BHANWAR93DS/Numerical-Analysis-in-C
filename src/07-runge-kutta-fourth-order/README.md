# Experiment 07 — Runge-Kutta Fourth Order

**Problem type:** system of first-order initial-value equations.

Classical RK4 evaluates four slopes per step for
```text
u' = -3u + 2v
v' =  3u - 4v
```

The weighted combination (k_1+2k_2+2k_3+k_4) gives the fourth-order update.

## Build and run

```bash
make exp07
./exp07
```
