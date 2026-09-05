#include <stdio.h>

static void euler_cauchy(double h, double x, double y, double z,
                         double *yn, double *zn)
{
    double k1y = h * z;
    double k1z = h * (x - 2.0 * z - y);

    double k2y = h * (z + k1z);
    double k2z = h * ((x + h) - 2.0 * (z + k1z) - (y + k1y));

    *yn = y + (k1y + k2y) / 2.0;
    *zn = z + (k1z + k2z) / 2.0;
}

int main(void)
{
    int n;
    double alpha, beta, h;

    double y1[51], z1[51];
    double y2[51], z2[51];

    printf("Enter alpha, beta: ");
    if (scanf("%lf %lf", &alpha, &beta) != 2)
        return 1;

    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 50)
        return 1;

    h = (beta - alpha) / n;

    /*
       y'' + 2y' + y = x
       y(alpha) = 0
       y'(beta) = 1

       Two trial IVPs:
       y1(alpha) = 0, z1(alpha) = 0
       y2(alpha) = 0, z2(alpha) = 1

       The required solution is
       y = y1 + lambda (y2 - y1),
       where lambda is chosen so that z(beta) = 1.
    */

    y1[0] = 0.0;
    z1[0] = 0.0;

    y2[0] = 0.0;
    z2[0] = 1.0;

    for (int j = 0; j < n; ++j)
    {
        double x = alpha + j * h;

        euler_cauchy(h, x, y1[j], z1[j], &y1[j + 1], &z1[j + 1]);
        euler_cauchy(h, x, y2[j], z2[j], &y2[j + 1], &z2[j + 1]);
    }

    double denominator = z2[n] - z1[n];

    if (denominator == 0.0)
    {
        fprintf(stderr, "Unable to determine the shooting parameter.\n");
        return 1;
    }

    double lambda = (1.0 - z1[n]) / denominator;

    printf("\n     x             y\n");

    for (int i = 0; i <= n; ++i)
    {
        double x = alpha + i * h;
        double y = y1[i] + lambda * (y2[i] - y1[i]);

        printf("%10.4f %13.6f\n", x, y);
    }

    return 0;
}
