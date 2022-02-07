#include <stdio.h>
int main()
{
    int m=0,n=0,i=0,temp=0;
    scanf("%d %d",&m,&n);
    if (m>n)//先判断m和n哪个大，不然for循环起点就会错，如果开始的数大，则互换
    {
        temp=m;
        m=n;
        n=temp;
    }
    for (i=m+1;i<n;i++)//遍历从m-n的每一个数，有符合条件的就输出
    {
        if (((i/10)%10)==3||((i/10)%10)==7)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}