#include <stdio.h>
#include <math.h>
int main ()
{
    printf("请输入一个整数");
    int num=0;
    scanf("%d",&num);
    int temp=num;
    int i=1;//使初始值为1 可以计算个位数
    while ((temp/10)!=0)//先让这个整数存进temp,再除10
    {
        temp/=10;
        i++;
    }
    printf("该整数有%d位\n",i);
    int k=0,a=0;
    for (k=2;k<(sqrt(num));k++)//从2开始，num的平方根结束
    {
        if ((num%k)==0)
        {
            printf("不是素数");
            break;
        }
        else 
        {
            a=1;//判断每除一个数都要除不尽
        }
    }
    if (a==1)
    {
        printf("是素数");
    }
    return 0;
}