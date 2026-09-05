#include <stdio.h>

static double f(double x,double y){ return (1.0+x*x)*y; }

int main(void){
    double x0,y0,dy0,h,xn,x,y,dy;
    printf("Enter x0, y0, y'0: ");
    if(scanf("%lf%lf%lf",&x0,&y0,&dy0)!=3) return 1;
    printf("Enter h: ");
    if(scanf("%lf",&h)!=1 || h<=0) return 1;
    printf("Enter xn: ");
    if(scanf("%lf",&xn)!=1 || xn<x0) return 1;
    x=x0; y=y0; dy=dy0;
    while(x < xn-1e-12){
        double step=h; if(x+step>xn) step=xn-x;
        /* The practical's formula uses a fourth stage depending on k4.
           For a reproducible implementation, solve the implicit stage for k4. */
        double k1=0.5*step*step*f(x,y);
        double k2=0.5*step*step*f(x+2*step/5,y+2*step*dy/5+4*k1/25);
        double k3=0.5*step*step*f(x+3*step/5,y+3*step*dy/5+4*k2/25);
        double A=0.5*step*step*(1+(x+step)*(x+step));
        double B=y+step*dy+8*k3/25;
        double k4=(A*B)/(1.0-8.0*A/25.0);
        y += step*dy+(23*k1+75*k2-27*k3+25*k4)/96.0;
        dy += (23*k1+125*k2-81*k3+125*k4)/(96.0*step);
        x += step;
        printf("x=%10.6f  y=%12.6f  dy=%12.6f\n",x,y,dy);
    }
    return 0;
}
