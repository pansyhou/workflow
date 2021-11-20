#include <stdio.h>
void main()
{
    int n=0,a=1,b=1,s=1,a1=0,a2=0;
    int num[10000]={1,1};
    for (int i=1;i<1000;i++)
    {
        num[i+1]=num[i]+num[i-1];
    }
    scanf("%d",&n);
    for (int k=0;k<n;k++)
    {
        printf("%d ",num[k]);
    }
    return 0;
}