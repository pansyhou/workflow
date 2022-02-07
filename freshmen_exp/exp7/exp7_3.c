/**
 * @file    exp7_3.c
 * @author  pansyhou
 * @brief   编写一个sort函数，实现对5个字符串按从大到小进行排序。
 *          在主程序中输入5字符串，调用sort(s,n)函数对n个字符串s进行排序，然后输出排序后的结果。
 */
#include <stdio.h>
#include <string.h>
#define M 5
void sort(char *s[],int n);
void main()
{
    char a[M][999];//先定义一个存原字符串的数组
    char *s[M];//定义一个含有M个字符串的数组指针
    for (int y=0;y<M;y++)
    {                 
        scanf("%s",&a[y]);//存入原数组
        *(s+y)=&a[y];//将原数组的首地址放入数组指针
    }
    sort(s,M);
    for (int u=0;u<M;u++)
    {
        printf("%s ",*(s+u));
    }
}
void sort(char *s[],int n)
{
    for (int k=0;k<n;k++)
    {
        for(int t=0;t<n-k;t++)
        {
            if(strcmp(s[t+1],s[t])>0)
            {
                char *temp;//这里是指针地址互换，不改变原数组
                temp=s[t+1];
                s[t+1]=s[t];
                s[t]=temp;
            }
        }
    }
}