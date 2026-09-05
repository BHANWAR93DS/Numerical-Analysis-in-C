#include <stdio.h>

static double f(int i,double x,double y,double z){ return i==1 ? z : x-2*z-y; }
static void rk4(double h,double x,double y,double z,double *yn,double *zn){
    double k1y=h*f(1,x,y,z), k1z=h*f(2,x,y,z);
    double k2y=h*f(1,x+h/2,y+k1y/2,z+k1z/2), k2z=h*f(2,x+h/2,y+k1y/2,z+k1z/2);
    double k3y=h*f(1,x+h/2,y+k2y/2,z+k2z/2), k3z=h*f(2,x+h/2,y+k2y/2,z+k2z/2);
    double k4y=h*f(1,x+h,y+k3y,z+k3z), k4z=h*f(2,x+h,y+k3y,z+k3z);
    *yn=y+(k1y+2*k2y+2*k3y+k4y)/6;
    *zn=z+(k1z+2*k2z+2*k3z+k4z)/6;
}
int main(void){
    int n; double a,b,h,y1[51],z1[51],y2[51],z2[51];
    printf("Enter alpha, beta: "); if(scanf("%lf%lf",&a,&b)!=2) return 1;
    printf("Enter n: "); if(scanf("%d",&n)!=1 || n<1 || n>50) return 1;
    h=(b-a)/n; y1[0]=0; z1[0]=1; y2[0]=1; z2[0]=0;
    for(int j=0;j<n;j++){
        rk4(h,a+j*h,y1[j],z1[j],&y1[j+1],&z1[j+1]);
        rk4(h,a+j*h,y2[j],z2[j],&y2[j+1],&z2[j+1]);
    }
    double lambda=(2-(2*y2[n]+z2[n]))/((2*y1[n]+z1[n])-(2*y2[n]+z2[n]));
    printf("\n     x             y\n");
    for(int i=0;i<=n;i++) printf("%10.4f %13.6f\n",a+i*h,lambda*y1[i]+(1-lambda)*y2[i]);
    return 0;
}
