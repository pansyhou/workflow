#include <stdio.h>
void main()
{
    char num1[100];
    int i=0,a=0,b=0,temp=0;
    scanf("%d %d",&a,&b);
    while(a>0)
    {
        temp=a%2;
        a/=2;
        num1[i]=temp+'0';
        i++;
    }
    b--;
    if(num1[b]=='0')
    {
        printf("false");
    }
    else
    {
        printf("true");
    }
    return 0;
}