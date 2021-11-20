#include <stdio.h>
#include <string.h>
int main()
{
    char STR1[50];
    char STR2[50];
    char *str1=STR1;
    char *str2=STR2;
    printf("请输入第一个字符串");
    gets(str1);
    printf("请输入第二个字符串");
    gets(str2);
    int num=0;
    num=strlen(str2);
    char *ret=strstr(str1, str2);
    int i=0;
    while (ret!=NULL)
    {
        i++;
        ret+=num;//指针地址加字符串2长度，跳过字符串2
        ret=strstr(ret,str2);//重置ret
    }
    printf("%d",i);
    return 0;
}