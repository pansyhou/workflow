#include <stdio.h>
#include <string.h>
void main()
{
    char a[1000];
    gets(a);
    int len=strlen(a);
    strlwr(a);//全部转成小写
    int num[9]={0};//数字ASCII码范围48-57,定义数字计数器数组
    int alpha[25]={0};//97-122定义字母计数器数组
    int i=0;
    for (;i<len;i++)
    {
        if(a[i]>47&&a[i]<58)
        {
            int temp=a[i]-48;//将字符的ascii码转成数字
            num[temp]++;//对应下标计数器加一
        }
        if (a[i]>96&&a[i]<123)
        {
            int temp=a[i]-97;
            alpha[temp]++;
        }
    }
    for (int i=0;i<10;i++)
    {
        printf("%c出现%d次\n",i+48,num[i]);//i+48转成ascii码输出
    }
    for (int i=0;i<26;i++)
    {
        printf("%c出现%d次\n",i+97,alpha[i]);
    }

}