# Experiment 11 — Shooting Method with Runge-Kutta Fourth Order

**Problem type:** second-order boundary-value problem.

The equation
```text
y'' + 2y' + y = x
```
is converted to a first-order system and integrated with classical RK4 for two trial solutions. Both trials satisfy the left boundary relation (y(0)+y'(0)=1); their linear combination is selected to satisfy (2y(1)+y'(1)=2).

## Build and run

```bash
make exp11
./exp11
```
