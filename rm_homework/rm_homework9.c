#include <stdio.h>
int main()
{
    char stce[200];
    gets(stce);//获取句子
    int i=0;
    for (i=0;stce[i]!='\0';i++)
    {
        if (stce[i]==' ')//判断有无空格
        {
            putchar('\n');//有就换行
        }
        else
        {
            putchar(stce[i]);//无就输出
        }
    }
}