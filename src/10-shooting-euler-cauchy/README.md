# Experiment 10 — Shooting Method with Euler-Cauchy

**Problem type:** second-order boundary-value problem.

The equation
```text
y'' + 2y' + y = x
```
is converted to a first-order system. Two trial initial slopes are integrated with Euler-Cauchy; the shooting parameter is chosen so that (y'(1)=1), while (y(0)=0) is preserved by both trial solutions.

## Build and run

```bash
make exp10
./exp10
```
