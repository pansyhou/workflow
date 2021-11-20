#include <stdio.h> 
int main()
{
    int a=0,b=0,c=0;
    scanf("%d %d %d",&a,&b,&c);
    int sum=0;
    double av;

    sum=a+b+c;
    av=sum/3.0;
    printf("sum=%d average=%f",sum,av);
    return 0;
}
