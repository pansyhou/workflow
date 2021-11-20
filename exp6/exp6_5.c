#include <stdio.h>
#include <string.h>
void normal(char a[]);
void digui(char a[]);
int len,i=0;
void main(void)
{
    char a[100];
    char *p=a;
    printf("请输入字符串");
    scanf("%s",&a);
    len=strlen(a);//字符串长度
    normal(a);
    digui(p);
}
void normal(char a[])
{
    
    for (int i=len;i>=0;i--)
    {
        printf("%c",a[i]);//从数组最后一位开始打印
    }
    printf("\n");
}
void digui(char *a)
{
    if(!*a) return;
    digui(a+1);//递归，从最末尾开始打印
    putchar(*a);
}