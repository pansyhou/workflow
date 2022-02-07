#include <stdio.h>
#include <string.h>
int main()
{
    char a[1000];//定义一个字符串数组a
    int t=0;
    gets(a);//获取字符串a
    while (a[t]!='\0')//计算字符串长度
    {
        t++;
    }
    strlwr(a);//将大写转成小写
    int i=0,j=0,l=0;
    int d=0,g=0,u=0,p=0;//dgut变量用于判断是否有dgut
    while(i<4)
    {
        for (int k=0;k<t;k++)
        {
            switch (i)
            {
            case 0:
                if (a[k]=='d')
                d=0;
                break;
            case 1:
                if (a[k]=='g')
                g=0;
                break;
            case 2:
                if (a[k]=='u')
                u=0;
                break;
            case 3:
                if (a[k]=='t')
                p=0;
                break;
            
            default:
                break;
            }
        }
        i++;
    }
    if (d==0&&g==0&&u==0&&p==0)
    {
        printf("能组成dgut");
    }
    else 
    {
        printf("不能组成dgut");
    }
    return 0;
}