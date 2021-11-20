#include <stdio.h>
int isPrime(int x,int knownPrimes[],int number0fKnownPrimes);
int main(void)
{
    const int number=10;
    int prime[number];
    prime[0]= 2;
    int count =1;
    int i=3;

    {
        int i;
        for (i=1;i<number;i++)
        {
        prime[i]=0;
        }
    }
    while (count <number)
    {
        if (isPrime(i,prime,count))
        {
            prime[count++]=i;
        }
        {
            printf("i=%d \tcnt=%d\t",i,count);
            int i;
            for (i=0;i<number;i++)
            {
                printf("%d\t",prime[i]);
            }
            printf("\n");
        }
        i++;
    }
    for (i=0;i<number;i++)
    {
        printf("%d",prime[i]);
        if((i+1)%5) printf("\t");
        else printf("\n");
    }
    return 0;
}
int isPrime(int x,int knownPrimes[],int number0fKnownPrimes)
{
    int ret =1;
    int i;
    for (i=0;i<number0fKnownPrimes;i++)
    {
        if(x%knownPrimes[i]==0)
        {
            ret=0;
            break;
        }
    }
    return ret;
}