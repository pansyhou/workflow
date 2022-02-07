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
    num=strlen(str2);//获取字符串长度
    char *ret=strstr(str1, str2);//获取字符串2在1中出现的地址
    int i=0;
    while (ret!=NULL)
    {
        i++;
        ret+=num;//指针地址加字符串2长度，跳过字符串2
        ret=strstr(ret,str2);//重置ret
    }
    if(i>0)printf("yes");
    else printf("NO");
    return 0;
}
/*其实可以用循环或者递归做的，（懒狗只想抄之前做过的hhhh）（能看懂就看吧x*/