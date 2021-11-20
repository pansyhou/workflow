#include <stdio.h>
int main()
{
    void strStr(char *str,char *need);
    int strlen(char *p);
    char *str='ssd';
    char *need='hdd';
    strStr(str,need);

}
int strlen(char* p)
{
    int i=0;
    while (p[i]!='\0')
    {
        p++;
        i++;
    }
    return i;
}
void strStr(char* str,char* need)
{
    int j=0,k=0;
    j=strlen(str);
    k=strlen(need);
    printf("%d",j);
}
