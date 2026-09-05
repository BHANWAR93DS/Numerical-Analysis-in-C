#include <stdio.h>
#define MAX 51

static void thomas(int n,const double a[],const double b[],const double c[],const double d[],double y[]){
    double cp[MAX],dp[MAX];
    cp[0]=c[0]/b[0]; dp[0]=d[0]/b[0];
    for(int i=1;i<n;i++){ double den=b[i]-a[i]*cp[i-1]; cp[i]=(i<n-1)?c[i]/den:0; dp[i]=(d[i]-a[i]*dp[i-1])/den; }
    y[n-1]=dp[n-1];
    for(int i=n-2;i>=0;i--) y[i]=dp[i]-cp[i]*y[i+1];
}
int main(void){
    int n; double x0,xn,dy0,dyn,h;
    double a[MAX],b[MAX],c[MAX],d[MAX],x[MAX],y[MAX];
    printf("Enter n, x0, y'(x0), xn, y'(xn): ");
    if(scanf("%d%lf%lf%lf%lf",&n,&x0,&dy0,&xn,&dyn)!=5 || n<2 || n>=MAX) return 1;
    h=(xn-x0)/n; for(int i=0;i<=n;i++) x[i]=x0+i*h;
    /* Ghost-point central differences give the endpoint equations. */
    for(int i=0;i<=n;i++){ a[i]=1; b[i]=-2-h*h; c[i]=1; d[i]=h*h*x[i]; }
    b[0]=b[0]-2*h*a[0]; c[0]=c[0]+a[0]; d[0]+=2*h*dy0;
    a[n]=a[n]+c[n]; b[n]=b[n]-2*h*c[n]; d[n]-=2*h*dyn;
    thomas(n+1,a,b,c,d,y);
    printf("\n     x             y\n");
    for(int i=0;i<=n;i++) printf("%10.4f %13.6f\n",x[i],y[i]);
    return 0;
}
