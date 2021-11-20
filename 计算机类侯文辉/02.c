#include <stdio.h>
void main()
{
    int start=0,len=0,temp=0;
    printf("len= ");
    scanf("%d",&len);
    printf("start= ");
    scanf("%d",&start);
    temp=start;
    for (int k=0;k<(len-1);k++)
    {
        temp=temp^(start+2);
        start+=2;
    }
    printf("%d",temp);
}