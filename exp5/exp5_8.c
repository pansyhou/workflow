#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int len=10;
    char a[len];
    int small_or_big=0;
    srand((unsigned int)time(NULL));
    for (int i=0;i<len;i++)//随机大小写
    {
        if (rand()%2==0)
        {
            small_or_big=64;
        }
        if (rand()%2==1)
        {
            small_or_big=96;
        }
        a[i]=((char)small_or_big+rand()%26);
    }
    printf("原英文字符串如下");
    for(int i=0;i<len;i++)
    {
        printf("%c",a[i]);
    }
    printf("\n请输入英文字符串");
    char b[len];
    int count=0;
    gets(b);//获取字符串
    for(int i=0;i<len;i++)
    {
        if(a[i]==b[i])count++;
    }
    double right_percent=((double)count/len)*100.0;//计算百分率
    printf("正确率为%.2f%%",right_percent);
}