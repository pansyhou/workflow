#include <stdio.h>
void main()
{
    int begus1=0,begus2=0,begus3=0;
    int gus1=0,gus2=0,gus3=0;
    scanf("%d %d %d",&begus1,&begus2,&begus3);
    scanf("%d %d %d",&gus1,&gus2,&gus3);
    if(begus1<0||begus2<0||begus3<0||gus1<0||gus2<0||gus3<0)
    {
        printf("请输入非负整数");
        scanf("%d %d %d",&begus1,&begus2,&begus3);
        scanf("%d %d %d",&gus1,&gus2,&gus3);
    }
    int count=0;
    if (begus1==gus1)
    {
        count++;
    }
    if (begus2==gus2)
    {
        count++;
    }
    if (begus3==gus3)
    {
        count++;
    }
    printf("%d",count);
    return 0;
}