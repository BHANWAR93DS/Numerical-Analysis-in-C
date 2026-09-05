# Experiment 05 — Euler Method

**Problem type:** system of first-order initial-value equations.

The program applies the explicit Euler update to the system
```text
u' = -3u + 2v
v' =  3u - 4v
```

At each step, the derivative at the current point is used to advance both components.

## Build and run

```bash
make exp05
./exp05
```

Input: number of steps, initial (t,u,v), and step size (h).
