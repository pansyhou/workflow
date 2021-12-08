/**
 * @file    exp7_6.c
 * @author  pansyhou
 * @brief 
            输入n个人的身高，然后从n个人中选出身高差值最小的两个人作为礼仪（如果差值相同的话，选取其中最高的两个人），要求输出两个礼仪的身高。
 */
#include <stdio.h>
#include <math.h>
void main()
{
    int height[100]={0};
    int index[99]={0};//用于寻找差值最小的索引
    char s;
    int i=0;
    printf("请输入每个人的身高，并用空格隔开，回车结束\n");
    for (i=0;i<999&&s!='\n';i++)
    {
        scanf("%d",&height[i]);
        s=getchar();
    }
    for(int k=0;k<i;k++)                        //先用冒泡对所有身高进行排序
    {
        for (int t=0;t<i-1;t++)
        {
            if (height[t+1]>height[t])
            {
                int temp=height[t+1];
                height[t+1]=height[t];
                height[t]=temp;
            }
        }
    }
    for (int t=0;t<i-1;t++)                     //用一个index的数组将两两差值存进去,abs是绝对值
    {
        index[t]=abs(height[t]-height[t+1]);
    }
    int min=200;
    for(int t=0;t<i-1;t++)                      //寻找最小值
    {
        if(index[t]<min)
        {
            min=index[t];
        }
    }
    for(int t=0;t<i-1;t++)                      //有两个最小值也没事，因为从身高高的开始遍历，找到就停止
    {
        if (index[t]==min)
        {
            printf("%d %d",height[t],height[t+1]);
            break;
        }
    }
}