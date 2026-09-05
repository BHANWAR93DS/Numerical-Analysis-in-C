#include <stdio.h>

static float f1(float t, float u, float v){ (void)t; return -3.0f*u + 2.0f*v; }
static float f2(float t, float u, float v){ (void)t; return 3.0f*u - 4.0f*v; }

int main(void){
    int n; float u0,v0,t0,h,t[51],u[51],v[51];
    printf("Enter n, t0, u0, v0, h:\n");
    if(scanf("%d%f%f%f%f",&n,&t0,&u0,&v0,&h)!=5 || n<1 || n>50 || h<=0) return 1;
    t[0]=t0; u[0]=u0; v[0]=v0;
    for(int i=0;i<n;i++){
        u[i+1]=u[i]+h*f1(t[i],u[i],v[i]);
        v[i+1]=v[i]+h*f2(t[i],u[i],v[i]);
        t[i+1]=t[i]+h;
    }
    printf("\n     t             u             v\n");
    for(int i=0;i<=n;i++) printf("%10.4f %13.6f %13.6f\n",t[i],u[i],v[i]);
    return 0;
}
