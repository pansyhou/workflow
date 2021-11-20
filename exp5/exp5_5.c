#include <stdio.h>
#include <string.h>
void main()
{
    char a[1000];
    gets(a);
    int len=strlen(a);
    strlwr(a);//97-122
    int num[9]={0};//48-57
    int alpha[25]={0};
    int i=0;
    for (;i<len;i++)
    {
        if(a[i]>47&&a[i]<58)
        {
            int temp=a[i]-48;
            num[temp]++;
        }
        if (a[i]>96&&a[i]<123)
        {
            int temp=a[i]-97;
            alpha[temp]++;
        }
    }
    for (int i=0;i<10;i++)
    {
        printf("%c出现%d次\n",i+48,num[i]);
    }
    for (int i=0;i<26;i++)
    {
        printf("%c出现%d次\n",i+97,alpha[i]);
    }

}