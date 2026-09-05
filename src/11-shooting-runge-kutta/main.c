#include <stdio.h>
#include <math.h>
#define max 51

float f(int i, float x, float y, float z)
{
    float fa;

    if(i == 1)
        fa = z;
    else
        fa = x - 2.0*z - y;

    return fa;
}

void rk4(float h, float x, float y, float z,
         float *y_next, float *z_next)
{
    float k1y, k2y, k3y, k4y;
    float k1z, k2z, k3z, k4z;

    k1y = h * f(1, x, y, z);
    k1z = h * f(2, x, y, z);

    k2y = h * f(1, x + h/2.0,y + k1y/2.0,z + k1z/2.0);

    k2z = h * f(2, x + h/2.0,y + k1y/2.0,z + k1z/2.0);

    k3y = h * f(1, x + h/2.0,y + k2y/2.0, z + k2z/2.0);

    k3z = h * f(2, x + h/2.0,y + k2y/2.0,z + k2z/2.0);

    k4y = h * f(1, x + h, y + k3y,z + k3z);

    k4z = h * f(2, x + h,y + k3y,z + k3z);

    *y_next = y + (k1y + 2*k2y + 2*k3y + k4y) / 6.0;
    *z_next = z + (k1z + 2*k2z + 2*k3z + k4z) / 6.0;
}

int main()
{
    int i, j, n;
    float x0, xn, h, lambda;
    float alpha, beta;
    float yt, zt, impyt, impzt;

    float y1[max], z1[max];
    float y2[max], z2[max];
    float y[max];

    printf("Enter the value of boundary points alpha, beta:\n");
    scanf("%f %f", &alpha, &beta);

    printf("Enter the value of n:\n");
    scanf("%d", &n);

    x0 = alpha;
    xn = beta;

    h = (xn - x0) / n;

    
    y1[0] = 0.0;
    z1[0] = 1.0;

    x0 = alpha;

    for(j = 1; j <= n; j++)
    {
        yt = y1[j-1];
        zt = z1[j-1];

        rk4(h, x0, yt, zt, &impyt, &impzt);

        y1[j] = impyt;
        z1[j] = impzt;

        x0 = x0 + h;
    }

    
    y2[0] = 1.0;
    z2[0] = 0.0;

    x0 = alpha;

    for(j = 1; j <= n; j++)
    {
        yt = y2[j-1];
        zt = z2[j-1];

        rk4(h, x0, yt, zt, &impyt, &impzt);

        y2[j] = impyt;
        z2[j] = impzt;

        x0 = x0 + h;
    }

    
    lambda = (2.0 - (2.0*y2[n] + z2[n])) /
             ((2.0*y1[n] + z1[n]) -
              (2.0*y2[n] + z2[n]));

    for(i = 1; i <= n; i++)
    {
        y[i] = lambda * y1[i]+ (1.0 - lambda) * y2[i];
    }

    
    printf("\n     x           y\n");

    x0 = alpha;

    for(i = 1; i <= n; i++)
    {
        x0 = x0 + h;

        printf("%-11.4f %-11.6f\n",x0, y[i]);
    }

    return 0;
}
