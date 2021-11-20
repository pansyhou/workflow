#include <stdio.h> 
int main()
{
    double x,y;
    
    scanf("%lf %lf",&x,&y);
    double L,S;
    L=2*x+2*y;
    S=x*y;
    printf("周长L=%f 面积S=%f",L,S);
    return 0;
}
