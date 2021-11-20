#include <stdio.h>
int strStr(char * str,char * need);
int main()
{
    char a[]="hello";
    char b[]="ll";
    char *p,*q;
    p=a;
    q=b;
    printf("%d",strStr(p,q));
}
int strStr(char * str,char * need)
{
    //获取各自字符串长度
    int a=0,b=0;
    while (str[a]!='\0')
    {
        a++;
    }
    while (need[b]!='\0')
    {
        b++;
    }
    //循环一对一找
    int i=0,j=0,c=0;//c控制返回值
    for (i=0;i+b<=a;i++)
    {
        int c=1;
        for (j=0;j<b;j++)
        {
            if (str[i+j]!=need[j])
            {
                c=0;
                break;
            }
        }
        if (c)
        {
            return j;
        }
    }
    return -1;
    
}