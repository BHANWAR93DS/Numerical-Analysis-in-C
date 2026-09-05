# Experiment 06 — Euler-Cauchy Method

**Problem type:** system of first-order initial-value equations.

The program uses the two-stage Euler-Cauchy (improved Euler/trapezoidal) update for
```text
u' = -3u + 2v
v' =  3u - 4v
```

The first stage estimates the slope at the current point; the second evaluates the slope at the predicted endpoint.

## Build and run

```bash
make exp06
./exp06
```
