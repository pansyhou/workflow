#include <stdio.h>
int main()
{
    int i=11,t=0,x=0;
    scanf("%d",&i);
    while (i>0)
    {
        t=i%2;
        i=i/2;
        x*=10;
        x=t+x;
        
        
    }
    printf("%d",x);
}