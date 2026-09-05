#include <stdio.h>

static void euler(double h,double x,double y,double z,double *yn,double *zn){
    *yn=y+h*z;
    *zn=z+h*(x-2*z-y);
}
int main(void){
    int n; double a,b,ya,yb,h;
    double y1[51],z1[51],y2[51],z2[51];
    printf("Enter alpha, beta, ya, yb: ");
    if(scanf("%lf%lf%lf%lf",&a,&b,&ya,&yb)!=4) return 1;
    printf("Enter n: "); if(scanf("%d",&n)!=1 || n<1 || n>50) return 1;
    h=(b-a)/n;
    y1[0]=ya; z1[0]=0; y2[0]=ya; z2[0]=1;
    for(int j=0;j<n;j++){
        euler(h,a+j*h,y1[j],z1[j],&y1[j+1],&z1[j+1]);
        euler(h,a+j*h,y2[j],z2[j],&y2[j+1],&z2[j+1]);
    }
    double lambda=(yb-y2[n])/(y1[n]-y2[n]);
    printf("\n     x             y\n");
    for(int i=0;i<=n;i++) printf("%10.4f %13.6f\n",a+i*h,lambda*y1[i]+(1-lambda)*y2[i]);
    return 0;
}
