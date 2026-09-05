#include <stdio.h>

static void euler_cauchy(double h,double x,double y,double z,double *yn,double *zn){
    double k1y=h*z, k1z=h*(x-2*z-y);
    double k2y=h*(z+k1z), k2z=h*((x+h)-2*(z+k1z)-(y+k1y));
    *yn=y+(k1y+k2y)/2.0;
    *zn=z+(k1z+k2z)/2.0;
}
int main(void){
    int n; double a,b,h;
    double y1[51],z1[51],y2[51],z2[51];
    printf("Enter alpha, beta: "); if(scanf("%lf%lf",&a,&b)!=2) return 1;
    printf("Enter n: "); if(scanf("%d",&n)!=1 || n<1 || n>50) return 1;
    h=(b-a)/n; y1[0]=0; z1[0]=0; y2[0]=1; z2[0]=0;
    for(int j=0;j<n;j++){
        euler_cauchy(h,a+j*h,y1[j],z1[j],&y1[j+1],&z1[j+1]);
        euler_cauchy(h,a+j*h,y2[j],z2[j],&y2[j+1],&z2[j+1]);
    }
    double lambda=(1-z1[n])/(z2[n]-z1[n]);
    printf("\n     x             y\n");
    for(int i=0;i<=n;i++) printf("%10.4f %13.6f\n",a+i*h,lambda*y2[i]+(1-lambda)*y1[i]);
    return 0;
}
