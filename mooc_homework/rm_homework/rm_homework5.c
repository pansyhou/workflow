#include <stdio.h>
int main()
{
    int i,j,k;
    int inp_num=0;
    //printf("已经尽力了，不知道怎么样才可以获取输入格式里的每一个整数");
    printf("请输入整数个数");
    scanf("%d",&inp_num);
    const int num=inp_num;
    int order[(num)];

    for (i=0;i<num;i++)//遍历获取全部整数
    {
        scanf("%d",&order[i]);
    }

    for (i=0;i<num;i++)
    {
        for (j=0;j<num-i;j++)
        {
            if (order[j]>order[j+1])//冒泡排序
            {
                k=order[j];
                order[j]=order[j+1];
                order[j+1]=k;
            }
        }
    }
    for (i=0;i<num;i++)
    {
        printf("%d ",order[i]);
    }
    return 0;
}