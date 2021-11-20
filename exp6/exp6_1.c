#include <stdio.h>
int isPrime(int i);
int main()
{
    int a=0,b=0;
    scanf("%d %d",&a,&b);
    for (;a<=b;a++)
    {
        if(isPrime(a))
        {
            printf("%d ",a);
        }
    }
    
}
int isPrime(int i)
{
    int l=1;
    for (int n=2;n<i;n++)
    {
        if (i%n==0)
        {
            l=0;
            return l;
        }
    }
    return l;
}