#define PI 3.14
#define L(R) 2*3.14*R
#define S(R) 3.14*R*R
#include <stdio.h>
int main()
{
    double R=0,l=0,s;
    printf("Enter radius:");
    scanf("%lf",&R);
    l=L(R);
    s=S(R);
    printf("l=%.2f,s=%.2f",l,s);
    return 0;
}