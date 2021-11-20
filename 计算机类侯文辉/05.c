#include <stdio.h>
void main()
{
    char a[200];
    gets(a);
    char b;
    scanf("%c",&b);
    int i=0,count=0;
    while(a[i]!='\0')
    {
        if(a[i]==b)
        {
            count++;
        }
        i++;
    }
    printf("出现%d次",count);
    return 0;
}