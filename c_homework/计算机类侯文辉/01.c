#include <stdio.h>
int main()
{
    int i=0,k=0,t=1;
    char a[100];
    while ((a[k]=getchar())!='\n')//获取并检测一共输入了多少个字符
    {
        k++;
    }
    k--;//由于输入多了一个回车需要减一个数才是一一对应
    while (i<k)//i为左边,k为右边，不断夹逼进行比较
    {
        if(a[i]!=a[k])//对比如果有不相同的数就可以直接break走人，并返回0
        {
            t=0;
            break;
        }
        i++;
        k--;
    }
    switch (t)
    {
    case 0:
        printf("false");
        break;
    
    case 1:
        printf("true");
        break;
    }
    return 0;
}