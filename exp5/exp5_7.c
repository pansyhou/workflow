#include <stdio.h>
void main(void)
{
    int count=1;
    int i=0,x=0;
    int num[20][20];
    for (;i<=19;i++)
    {
        if(i%2!=0)
        {
            for(x=0;x<=i;x++)
            {
                num[x][i-x]=count;
                count++;
            }
        }
        if(i%2==0)
        {
            for(x=0;x<=i;x++)
            {
                num[i-x][x]=count;
                count++;
            }
        }
    }
    for(i=0;i<=19;i++)
    {
        for(x=0;x<=19-i;x++)
        {
            printf("%d ",num[i][x]);
        }
        printf("\n");
    }    
}